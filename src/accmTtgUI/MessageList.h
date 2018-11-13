#include <QAbstractListModel>
#include <memory>
#include "IBusiness.h"
#include "Message.h"

class MessageList : public QAbstractListModel {
  Q_OBJECT
 public:
  enum PatientRoles {
    idRole = Qt::UserRole + 1,
    nameRole,
    surnameRole,
    emailRole,
    dobRole
  };
  MessageList(QObject *parent, std::shared_ptr<IBusiness> &business_logic);

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

 public slots:
  void InsertMessage(QVector<Message *> patients);

 private:
  QVector<Message *> patient_list_;
  std::shared_ptr<IBusiness> business_logic_;
};
