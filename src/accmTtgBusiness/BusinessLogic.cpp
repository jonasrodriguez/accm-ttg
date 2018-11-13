#include "BusinessLogic.h"
#include <QDebug>
#include "DbManager.h"

BusinessLogic::BusinessLogic() { db_ = std::unique_ptr<IDb>(new DbManager); }

void BusinessLogic::StartUp() { db_->StartUp(); }

void BusinessLogic::ShutDown() {
  //  QCoreApplication::processEvents();
  //  db_.reset();
}
