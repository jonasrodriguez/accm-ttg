#include "Dashboard.h"

Dashboard::Dashboard(QObject *parent,
                     std::shared_ptr<IBusiness> &business_logic)
    : QObject(parent), business_logic_(business_logic) {
  CreateNavigationMap();
  UpdateNavigation(navEnum::message);
}

void Dashboard::CreateNavigationMap() {
  navMap_.insert(navEnum::home, nav_home);
  navMap_.insert(navEnum::conversation, nav_conversation);
  navMap_.insert(navEnum::message, nav_message);
}

void Dashboard::UpdateNavigation(int nav) {
  auto map = navMap_.find(nav);
  navigation_ = map.value();
  emit navigationChanged();
}

void Dashboard::buttonNavHome() { UpdateNavigation(navEnum::home); }

void Dashboard::buttonNavConversation() {
  UpdateNavigation(navEnum::conversation);
}

void Dashboard::buttonOpenMessage() { UpdateNavigation(navEnum::message); }

bool Dashboard::getHideNav() const {
  return (navigation_ == nav_home) ? true : false;
}
