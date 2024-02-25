#ifndef CPP_PROJECT_TEMPLATE_EXAMPLES_SMARTPTREXAMPLE_H_
#define CPP_PROJECT_TEMPLATE_EXAMPLES_SMARTPTREXAMPLE_H_

#include <iostream>

inline void memoryLeakExample() {
  {
    auto some_value = new int(2);
    // Здесь выделяется динамическая память под int со значением 2.
    // На выделенную память указывает указатель some_value
    // Помните! Указатель является обычной переменной
  }

  // После выхода из области видимости (scope), в котором была создана переменная
  // some_value, она уничтожается. Однако, int, который был выделен и лежал в ДИНАМИЧЕСКОЙ ПАМЯТИ, не будет уничтожен
  // Кроме того, т.к. на него больше нет никакого указателя, то мы не можем получить к нему доступ.
  // Тем не менее само место остается выделенным до конца исполнения программы.
  // Это называется утечкой памяти.
}

inline void uniquePtrExample() {
  {
    auto some_value_unique = std::make_unique<int>(2);
    // Здесь выделяется динамическая память под int со значением 2.
    // На выделенную память указывает указатель some_value_unique
  }
  // После выхода из области видимости (scope), в котором была создана переменная
  // some_value_unique, она уничтожается. Т.к. some_value_unique был unique_ptr,
  // то и в динамическая память, выделенная под int, на который указывалось, будет освобождена.
  // Утечки памяти не будет (в отличие от примера с обычным указателем).

  // Помните! Нельзя сделать несколько unique_ptr указывающих на одну и ту же область памяти!
}

inline void sharedPtrExample() {
  auto shared_ptr_example_1 = std::make_shared<int>(2);
  std::cout << "Ref count for shared_ptr (after shared_ptr_example_1 creation):\t"
            << shared_ptr_example_1.use_count() << "\t" << __func__ << std::endl;
  // Теперь в динамической памяти выделен int со значением 2. На него указывает указатель shared_ptr_example_1
  {
    auto shared_ptr_example_2 = shared_ptr_example_1;

    std::cout << "Ref count for shared_ptr (after shared_ptr_example_2 creation):\t"
      << shared_ptr_example_2.use_count() << "\t" << __func__ << std::endl;

    // Теперь ссылок стало 2 шт.
  }
  // После выхода из области видимости переменная (которая является указателем) shared_ptr_example_2 уничтожена
  // Теперь ссылок стало на 1 меньше. Т.е. 1

  std::cout << "Ref count for shared_ptr (after exiting the scope of shared_ptr_example_2):\t"
            << shared_ptr_example_1.use_count() << "\t" << __func__ << std::endl;

  // После выхода из функции уничтожается shared_ptr_example (указатель!)
  // Объект, на который он указывал тоже уничтожается, потому что больше нет ссылок
}

inline void weakPtrExample() {
  auto shared_ptr_example_1 = std::make_shared<int>(2);
  std::cout << "Ref count for shared_ptr (after shared_ptr_example_1 creation):\t"
            << shared_ptr_example_1.use_count() << "\t" << __func__ << std::endl;

  auto shared_ptr_example_2 = shared_ptr_example_1;
  // Количество ссылок увеличилось
  std::cout << "Ref count for shared_ptr (after shared_ptr_example_2 creation):\t"
            << shared_ptr_example_1.use_count() << "\t" << __func__ << std::endl;


  auto weak_ptr_example = std::weak_ptr<int>(shared_ptr_example_1);
  // Количетсво ссылок не изменилось
  std::cout << "Ref count for shared_ptr (after weak_ptr_example creation):\t"
            << shared_ptr_example_1.use_count() << "\t" << __func__ << std::endl;
}

inline void weakPtrExample2() {
  std::weak_ptr<int> weak_ptr_example;
  {
    auto shared_ptr_example = std::make_shared<int>(2);
    // Выделяем память, создаем умный указатель
    std::cout << "Ref count for shared_ptr (after shared_ptr_example creation):\t"
              << shared_ptr_example.use_count() << "\t" << __func__ << std::endl;

    weak_ptr_example = std::weak_ptr<int>(shared_ptr_example);
    // Количество ссылок не изменяется
    std::cout << "Ref count for shared_ptr (after weak_ptr_example creation):\t"
              << shared_ptr_example.use_count() << "\t" << __func__ << std::endl;
  }

  // Количетсво ссылок достигает 0 и объект (int) уничтожается из динамической памяти.
  // Однако, благодаря тому, что мы использовали weak_ptr у нас остается указатель.
  // Чтобы узнать, осталось ли ещё выделенная память, на которую указывает weak_ptr
  // можно воспользоваться методом expired

  std::cout << "Weak ptr is expired:\t" << weak_ptr_example.expired() << "\t" << std::endl;

  // Если мы попробуем использовать weak_ptr как shared_ptr и разыменуем его, то получим критическую
  // ошибку Segmentation Fault
//    std::cout << *weak_ptr_example.lock().get() << "A";
}


#endif //CPP_PROJECT_TEMPLATE_EXAMPLES_SMARTPTREXAMPLE_H_
