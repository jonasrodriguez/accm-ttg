#include <QMap>
#include <QObject>
#include <memory>
#include "IBusiness.h"

static const QString nav_home = "Home.qml";
static const QString nav_conversation = "ConversationArea.qml";
static const QString nav_message = "Message.qml";

enum navEnum { home = 1, conversation, message };

class Dashboard : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString navigation READ getNavigation NOTIFY navigationChanged)
  Q_PROPERTY(bool hideNav READ getHideNav NOTIFY navigationChanged)

 public:
  Dashboard(QObject *parent, std::shared_ptr<IBusiness> &business_logic);

  QString getNavigation() const { return navigation_; }
  bool getHideNav() const;

 signals:
  void navigationChanged();

 public slots:
  void buttonNavHome();
  void buttonNavConversation();
  void buttonOpenMessage();

 private:
  void UpdateNavigation(int nav);
  void CreateNavigationMap();

 private:
  std::shared_ptr<IBusiness> business_logic_;
  QString navigation_;
  QMap<int, QString> navMap_;
};
