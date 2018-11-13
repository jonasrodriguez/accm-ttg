#pragma once
#include <memory>
#include "IBusiness.h"
#include "IDb.h"

class BusinessLogic : public IBusiness {
 public:
  BusinessLogic();
  ~BusinessLogic() = default;

  void StartUp() override;
  void ShutDown() override;

 private:
  std::unique_ptr<IDb> db_;
};
