#include "MessageList.h"

QHash<int, QByteArray> MessageList::roleNames() const {
  QHash<int, QByteArray> roles;

  roles[idRole] = json_id.toUtf8();
  roles[nameRole] = json_name.toUtf8();
  roles[surnameRole] = json_surname.toUtf8();
  roles[emailRole] = json_email.toUtf8();
  roles[dobRole] = json_dob.toUtf8();

  return roles;
}

MessageList::MessageList(QObject *parent,
                         std::shared_ptr<IBusiness> &business_logic)
    : QAbstractListModel(parent), business_logic_(business_logic) {}

int MessageList::rowCount(const QModelIndex & /* parent */) const {
  return patient_list_.size();
}

QVariant MessageList::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) return QVariant();

  if (index.row() >= patient_list_.size() || index.row() < 0) return QVariant();

  switch (role) {
      //    case PatientRoles::idRole:
      //      return patient_list_.at(index.row()).id;
      //    case PatientRoles::nameRole:
      //      return patient_list_.at(index.row()).name;
      //    case PatientRoles::surnameRole:
      //      return patient_list_.at(index.row()).surname;
      //    case PatientRoles::emailRole:
      //      return patient_list_.at(index.row()).email;
      //    case PatientRoles::dobRole: {
      //      QString dob(patient_list_.at(index.row()).dateOfBirth);
      //      return dob.left(4) + "/" + dob.mid(4, 2) + "/" + dob.mid(6, 2);
      //    }
    default:
      return QVariant();
  }
}

void MessageList::InsertMessage(QVector<Message *> patients) {
  // Clear list before inserting new patients
  if (!patient_list_.empty()) {
    beginRemoveRows(QModelIndex(), 0, patient_list_.size() - 1);
    patient_list_.clear();
    endRemoveRows();
  }

  beginInsertRows(QModelIndex(), patient_list_.size(),
                  patient_list_.size() + patients.size() - 1);
  for (auto i : patients) {
    patient_list_.push_back(i);
  }
  endInsertRows();
}
