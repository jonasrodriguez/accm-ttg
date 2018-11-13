#pragma once
#include "AccmDefinitions.h"

/*!
 * \brief The Message class is the abstraction of all the messages defined by
 * the  POCT1-A protocol that Accm can deal with.
 *
 * The proper way to manage the messages is by using std::unique_ptr<> and move
 * them successively. That's way both copy constructor and assignment operator
 * functions are deleted.
 */
class Message {
 public:
  /*!
   * \brief Default constructor.
   */
  explicit Message() = default;
  /*!
   * \brief Default destructor.
   */
  virtual ~Message() = default;
  /*!
   * \brief Copy constructor is deleted.
   */
  Message(const Message&) = delete;
  /*!
   * \brief Assignment operator is deleted.
   */
  Message& operator=(const Message&) = delete;
  /*!
   * \brief Get a reference to the header of the message. This is the common
   * element between all the messages.
   * \return a pointer to the header.
   * \see SetHeader
   */
  inline const accm::Header* GetHeader() const { return &header_; }
  /*!
   * \brief Set the header.
   * \param head The header from which to get the values.
   * \see GetHeader
   */
  inline void SetHeader(const accm::Header& head) {
    header_ = head;
    header_.control_id = std::to_string(++kMessageNum);
  }
  /*!
   * \brief Set the header.
   * \param head The header from which to get the values.
   * \param control_id The control_id of the header. Used when deserializing
   * messages in order to avoid the automatic control sequence.
   */
  inline void SetHeader(const accm::Header& head,
                        const std::string& control_id) {
    header_ = head;
    header_.control_id = control_id;
  }
  /*!
   * \brief Get the message type. Aimed to identify which kind of message it is.
   * \return The message type.
   */
  virtual accm::Header::MsgType GetMessageType() const = 0;

  /*!
   * \brief Point the message position in a conversation.
   */
  static unsigned int kMessageNum;

 protected:
  accm::Header header_;
};
///////////////////////////////////
/*!
 * \brief The MessageAck class implements the ACK.R01 message defined by the
 * POCT1-A standard.
 */
class MessageAck : public Message {
 public:
  /*!
   * \brief Default constructor.
   */
  explicit MessageAck() = default;
  /*!
   * \brief Default destructor.
   */
  ~MessageAck() override = default;
  /*!
   * \brief Copy constructor is deleted.
   */
  MessageAck(const MessageAck&) = delete;
  /*!
   * \brief Assignment operator is deleted.
   */
  MessageAck& operator=(const MessageAck&) = delete;
  /*!
   * \brief Get the body of the ACK.R01 message.
   * \return A reference to the ACK.R01's body.
   * \see SetAck
   */
  inline const accm::Ack* GetAck() const { return &ack_; }
  /*!
   * \brief Get the message type.
   * \return accm::Header::MsgType::ACK_R01
   */
  inline accm::Header::MsgType GetMessageType() const override {
    return accm::Header::MsgType::ACK_R01;
  }
  /*!
   * \brief Set the body of the ACK.R01.
   * \param ack The ACK.R01 body from which to get the values.
   * \see GetAck
   */
  inline void SetAck(const accm::Ack& ack) { ack_ = ack; }

 private:
  accm::Ack ack_;
};
///////////////////////////////////
/*!
 * \brief The MessageDeviceStatus class implements the DST.R01 message
 * defined by the POCT1-A standard.
 */
class MessageDeviceStatus : public Message {
 public:
  /*!
   * \brief Default constructor.
   */
  explicit MessageDeviceStatus() = default;
  /*!
   * \brief Default destructor.
   */
  ~MessageDeviceStatus() override = default;
  /*!
   * \brief Copy constructor is deleted.
   */
  MessageDeviceStatus(const MessageDeviceStatus&) = delete;
  /*!
   * \brief Assignment operator is deleted.
   */
  MessageDeviceStatus& operator=(const MessageDeviceStatus&) = delete;
  /*!
   * \brief Get the body of the DST.R01 message.
   * \return A reference to the DST.R01's body.
   * \see SetDeviceStatus
   */
  inline const accm::DeviceStatus* GetDeviceStatus() const {
    return &device_status_;
  }
  /*!
   * \brief Get the message type.
   * \return accm::Header::MsgType::DST_R01
   */
  inline accm::Header::MsgType GetMessageType() const override {
    return accm::Header::MsgType::DST_R01;
  }
  /*!
   * \brief Set the body of the DST.R01 message.
   * \param device The DST.R01 body from which to get the values.
   * \see GetDeviceStatus
   */
  inline void SetDeviceStatus(const accm::DeviceStatus& device) {
    device_status_ = device;
  }

 private:
  accm::DeviceStatus device_status_;
};
///////////////////////////////////
/*!
 * \brief The MessageEscape class implements the ESC.R01 message
 * defined by the POCT1-A standard.
 */
class MessageEscape : public Message {
 public:
  /*!
   * \brief Default constructor.
   */
  explicit MessageEscape() = default;
  /*!
   * \brief Default destructor.
   */
  ~MessageEscape() override = default;
  /*!
   * \brief Copy constructor is deleted.
   */
  MessageEscape(const MessageEscape&) = delete;
  /*!
   * \brief Assignment operator is deleted.
   */
  MessageEscape& operator=(const MessageEscape&) = delete;
  /*!
   * \brief Get the body of the ESC.R01 message.
   * \return A reference to the ESC.R01's body.
   * \see SetEscape
   */
  inline const accm::Escape* GetEscape() const { return &escape_; }
  /*!
   * \brief Get the message type.
   * \return accm::Header::MsgType::ESC_R01
   */
  inline accm::Header::MsgType GetMessageType() const override {
    return accm::Header::MsgType::ESC_R01;
  }
  /*!
   * \brief Set the body of the ESC.R01 message.
   * \param escape The ESC.R01 body from which to get the values.
   * \see GetEscape
   */
  inline void SetEscape(const accm::Escape& escape) { escape_ = escape; }

 private:
  accm::Escape escape_;
};
///////////////////////////////////
/*!
 * \brief The MessageEndOfTopic class implements the EOT.R01 message
 * defined by the POCT1-A standard.
 */
class MessageEndOfTopic : public Message {
 public:
  /*!
   * \brief Default constructor.
   */
  explicit MessageEndOfTopic() = default;
  /*!
   * \brief Default destructor.
   */
  ~MessageEndOfTopic() override = default;
  /*!
   * \brief Copy constructor is deleted.
   */
  MessageEndOfTopic(const MessageEndOfTopic&) = delete;
  /*!
   * \brief Assignment operator is deleted.
   */
  MessageEndOfTopic& operator=(const MessageEndOfTopic&) = delete;
  /*!
   * \brief Get the body of the EOT.R01 message.
   * \return A reference to the EOT.R01's body.
   * \see SetEndOfTopic
   */
  inline const accm::EndOfTopic* GetEndOfTopic() const {
    return &end_of_topic_;
  }
  /*!
   * \brief Get the message type.
   * \return accm::Header::MsgType::EOT_R01
   */
  inline accm::Header::MsgType GetMessageType() const override {
    return accm::Header::MsgType::EOT_R01;
  }
  /*!
   * \brief Set the body of the EOT.R01 message.
   * \param end_of_topic The EOT.R01 body from which to get the values.
   * \see GetEndOfTopic
   */
  inline void SetEndOfTopic(const accm::EndOfTopic& end_of_topic) {
    end_of_topic_ = end_of_topic;
  }

 private:
  accm::EndOfTopic end_of_topic_;
};

///////////////////////////////////
/*!
 * \brief The MessageHello class implements the HEL.R01 message
 * defined by the POCT1-A standard.
 */
class MessageHello : public Message {
 public:
  /*!
   * \brief Default constructor.
   */
  explicit MessageHello() = default;
  /*!
   * \brief Default destructor.
   */
  ~MessageHello() override = default;
  /*!
   * \brief Copy constructor is deleted.
   */
  MessageHello(const MessageHello&) = delete;
  /*!
   * \brief Assignment operator is deleted.
   */
  MessageHello& operator=(const MessageHello&) = delete;
  /*!
   * \brief Get the connection's profile of the HEL.R01 message.
   * \return A reference to the connection's profile.
   * \see SetConnectionProfile
   * \see accm::ConnectionProfile
   */
  //  inline const accm::ConnectionProfile* GetConnectionProfile() const {
  //    return &device_.connection_profile;
  //  }
  /*!
   * \brief Get the Device (<DEV>) from the HEL.R01 message.
   * \return A reference to the Device information.
   * \see SetDevice
   * \see accm::Device
   */
  inline const accm::Device* GetDevice() const { return &device_; }
  /*!
   * \brief Get the Device Static capabilities (<DSC>) from the HEL.R01 message.
   * \return A reference to the Device Static capabilities information.
   * \see SetDeviceStaticCapabilities
   * \see accm::DeviceStaticCapabilities
   */
  //  inline const accm::DeviceStaticCapabilities* GetDeviceStaticCapabilities()
  //      const {
  //    return &device_.static_capabilities;
  //  }
  /*!
   * \brief Get the message type.
   * \return accm::Header::MsgType::HEL_R01
   */
  inline accm::Header::MsgType GetMessageType() const override {
    return accm::Header::MsgType::HEL_R01;
  }
  /*!
   * \brief Set the conneciton's profile.
   * \param connection the connection's profile from which to get the values.
   * \see GetConnectionProfile
   * \see accm::ConnectionProfile
   */
  //  inline void SetConnectionProfile(const accm::ConnectionProfile&
  //  connection) {
  //    device_.connection_profile = connection;
  //  }
  /*!
   * \brief Set the Device (<DEV>) information.
   * \param device The Device from which to get the values.
   * \see GetDevice
   * \see accm::Device
   */
  inline void SetDevice(const accm::Device& device) { device_ = device; }
  /*!
   * \brief Set the Device Static capabilities (<DSC>) information.
   * \param capabilities The Device Static capabilities from which to get the
   * values.
   * \see GetDeviceStaticCapabilities
   * \see accm::DeviceStaticCapabilities
   */
  //  inline void SetDeviceStaticCapabilities(
  //      const accm::DeviceStaticCapabilities& capabilities) {
  //    device_.static_capabilities = capabilities;
  //  }

 private:
  accm::Device device_;
};
///////////////////////////////////
/*!
 * \brief The MessageObservations class implements both OBS.R01 and OBS.R02
 * messages defined by the POCT1-A standard.
 */
class MessageObservations : public Message {
 public:
  /*!
   * \brief Default constructor.
   * \param isPatientInfo Whether it is patient (OBS.R01) or non-patient
   * (OBS.R02).
   */
  explicit MessageObservations(bool isPatientInfo)
      : msg_type((isPatientInfo ? accm::Header::MsgType::OBS_R01
                                : accm::Header::MsgType::OBS_R02)) {}
  /*!
   * \brief Default destructor.
   */
  ~MessageObservations() override = default;
  /*!
   * \brief Copy constructor is deleted.
   */
  MessageObservations(const MessageObservations&) = delete;
  /*!
   * \brief Assignment operator is deleted.
   */
  MessageObservations& operator=(const MessageObservations&) = delete;
  /*!
   * \brief Get the message type.
   * \return accm::Header::MsgType::OBS_R01 or accm::Header::MsgType::OBS_R02.
   * \see SetMessageType
   */
  inline accm::Header::MsgType GetMessageType() const override {
    return msg_type;
  }
  /*!
   * \brief Get the body of the OBS.* message.
   * \return A reference to the service of the OBS.* message.
   * \see SetService
   */
  inline const accm::Service* GetService() const { return &service_; }
  /*!
   * \brief Set the body of the OBS.* message.
   * \param service The OBS.* body from which to get the values.
   * \see GetService
   */
  inline void SetService(const accm::Service& service) { service_ = service; }

 private:
  accm::Service service_;
  accm::Header::MsgType msg_type;
};
///////////////////////////////////
/*!
 * \brief The MessageRequest class implements the REQ.R01 message
 * defined by the POCT1-A standard.
 */
class MessageRequest : public Message {
 public:
  /*!
   * \brief Default constructor.
   */
  explicit MessageRequest() = default;
  /*!
   * \brief Default destructor.
   */
  ~MessageRequest() override = default;
  /*!
   * \brief Copy constructor is deleted.
   */
  MessageRequest(const MessageRequest&) = delete;
  /*!
   * \brief Assignment operator is deleted.
   */
  MessageRequest& operator=(const MessageRequest&) = delete;
  /*!
   * \brief Get the message type.
   * \return accm::Header::MsgType::REQ_R01
   */
  inline accm::Header::MsgType GetMessageType() const override {
    return accm::Header::MsgType::REQ_R01;
  }
  /*!
   * \brief Get the body of the REQ.R01 message.
   * \return A reference to the REQ.R01's body.
   * \see SetRequest
   */
  inline const accm::Request* GetRequest() const { return &request_; }
  /*!
   * \brief Set the body of the REQ.R01.
   * \param request The REQ.R01 body from which to get the values.
   * \see GetRequest
   */
  inline void SetRequest(const accm::Request& request) { request_ = request; }

 private:
  accm::Request request_;
};
///////////////////////////////////
/*!
 * \brief The MessageTerminate class implements the END.R01 message
 * defined by the POCT1-A standard.
 */
class MessageTerminate : public Message {
 public:
  /*!
   * \brief Default constructor.
   */
  explicit MessageTerminate() = default;
  /*!
   * \brief Default destructor.
   */
  ~MessageTerminate() override = default;
  /*!
   * \brief Copy constructor is deleted.
   */
  MessageTerminate(const MessageTerminate&) = delete;
  /*!
   * \brief Assignment operator is deleted.
   */
  MessageTerminate& operator=(const MessageTerminate&) = delete;
  /*!
   * \brief Get the message type.
   * \return accm::Header::MsgType::END_R01
   */
  inline accm::Header::MsgType GetMessageType() const override {
    return accm::Header::MsgType::END_R01;
  }
  /*!
   * \brief Get the body of END.R01 message.
   * \return A reference to the END.R01's body.
   * \see SetTerminate
   */
  inline const accm::Terminate* GetTerminate() const { return &terminate_; }
  /*!
   * \brief Set the body of the END.R01.
   * \param terminate The END.R01 body from which to get the values.
   * \see GetTerminate
   */
  inline void SetTerminate(const accm::Terminate& terminate) {
    terminate_ = terminate;
  }

 private:
  accm::Terminate terminate_;
};
