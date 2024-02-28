#ifndef TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_REGREADDIVIDER_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_REGREADDIVIDER_H_

#include <cmath>
#include <vector>


struct RegReadData {
  RegReadData(int v_reg_num, int v_reg_count) {
    reg_num = v_reg_num;
    reg_count = v_reg_count;
  }

  int reg_num = 0;
  int reg_count = 1;
};

class RegReadDivider {
 public:
  RegReadDivider() {

  }

  RegReadDivider(int reg_num, int regs_count, int reg_per_request) {
    setParams(reg_num, regs_count, reg_per_request);
  }

  inline void setParams(int reg_num, int regs_count, int reg_per_request) {
    _reg_num = reg_num;
    _reg_count = regs_count;
    _reg_per_request = reg_per_request;
  }

  inline int getCurrentRegNum() {
    return _current_reg_num;
  }

  inline int getCurrentRegCount() {
    return _current_reg_count;
  }

  inline std::vector<RegReadData> getRegReadData() {
    std::vector<RegReadData> result;
    _current_reg_num = 0;
    if (_reg_count <= _reg_per_request) {
      result.emplace_back(_reg_num, _reg_count);
    } else {
      result.emplace_back(_current_reg_num, _reg_per_request);

      while (_current_reg_num + 2 * _reg_per_request < _reg_count) {
        _current_reg_num += _reg_per_request;
        _current_reg_count = _reg_per_request;
        result.emplace_back(_current_reg_num, _current_reg_count);
      }

      _current_reg_num += _reg_per_request;
      _current_reg_count = _reg_count - _current_reg_num;
      // std::cout << "TTTT\t " << _current_reg_count << " " << _current_reg_num << std::endl;
      if (_current_reg_count > 0)
        result.emplace_back(_current_reg_num, _current_reg_count);
    }

    return result;
  }

  inline void update() {
    if (_reg_count < _reg_per_request) {
      _current_reg_num = _reg_num;
      _current_reg_count = _reg_count;
    } else {
      int tmp = _current_reg_num + _reg_per_request;
      if (tmp >= _reg_count) {
        _current_reg_num = 0;
        _current_reg_count = _reg_count;
      } else {
        _current_reg_num = tmp;
        _current_reg_count = _reg_count - _current_reg_num;
      }
    }
  }

 private:
  int _reg_per_request = 125;

  int _current_reg_num = 0;
  int _current_reg_count = 1;

  int _reg_num = 0;
  int _reg_count = 1;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_REGREADDIVIDER_H_
