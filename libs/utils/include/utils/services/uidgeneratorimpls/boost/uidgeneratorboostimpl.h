#ifndef TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_BACKGROUND_IMPL1_UIDGENERATORIMPLS_BOOST_UIDGENERATORBOOSTIMPL_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_BACKGROUND_IMPL1_UIDGENERATORIMPLS_BOOST_UIDGENERATORBOOSTIMPL_H_

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>

#include <utils/services/uidgenerator.h>


class UIDGeneratorBoostImpl: public UIDGenerator {
 public:
  virtual ~UIDGeneratorBoostImpl() = default;
  std::string generateUIDString() override;

 private:
  boost::uuids::random_generator _generator;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_BACKGROUND_IMPL1_UIDGENERATORIMPLS_BOOST_UIDGENERATORBOOSTIMPL_H_
