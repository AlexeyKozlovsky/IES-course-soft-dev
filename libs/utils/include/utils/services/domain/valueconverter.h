#ifndef TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_VALUECONVERTER_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_VALUECONVERTER_H_

/**
 * Class for converting values between hw discr. values to user-friendly values
*/
template <typename T>
class DiscreteValueConverter {
 public:
  DiscreteValueConverter() {

  }

  DiscreteValueConverter(int mult_discrete, int shift_discrete, int round) {
    setParams(mult_discrete, shift_discrete, round);
  }

  void setParams(int mult_discrete, int shift_discrete, int round) {
    _mult_discrete = mult_discrete;
    _shift_discrete = shift_discrete;
    _round = round;
  }

  T toValue(T input) {
    T result = input * _mult_discrete + _shift_discrete;

    // T result_div = result / _round;

    // T upper_res = (result_div + 1) * _round;
    // T under_res = result_div * round;

    // if (abs(upper_res - result) <= abs(result - under_res)) {
    //   result = upper_res;
    // } else {
    //   result = under_res;
    // }

    return result;
  }

  T toDiscretes(T input) {
    if (input <= _shift_discrete) return 0;
    T result_div = input / _round;
    T upper_res = (result_div + 1) * _round;
    T under_res = result_div * _round;

    if ((upper_res - input) <= (input - under_res)) {
      result_div = upper_res;
    } else {
      result_div = under_res;
    }

    T result = result_div - _shift_discrete;


    result /= _mult_discrete;
    return result;
  }

 private:
  int _mult_discrete = 25;
  int _shift_discrete = 100;

  int _round = 100;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_VALUECONVERTER_H_
