#pragma once
#include <list>
#include <optional>
#include <set>
#include <string>
#include <thread>

namespace accm {
/*!
 * \brief The NullCode enum
 */
enum NullCode {
  NI,   /**< No information */
  NA,   /**< Not applicable */
  UNK,  /**< Unknown */
  NASK, /**< Not asked */
  ASKU, /**< Asked but unknown */
  NAV,  /**< Not available */
  OTH,  /**< Other */
  PINF, /**< Positive infinity */
  NINF, /**< Negative infinity */
  NOT_NULL = -1
};

/*!
 * \brief The PN struct is used to communicate the elements of an individual's
 * name.
 */
struct PN {
  /*!
   * \brief Default constructor.
   */
  PN() = default;
  /*!
   * \brief Copy constructor.
   * \param pn The PN to copy.
   */
  PN(const PN& pn) { *this = pn; }
  /*!
   * \brief Overloading assignment operator.
   * \param pn The PN's values to assign.
   * \return PN
   */
  PN& operator=(const PN& pn) {
    if (this == &pn) {
      return *this;
    }
    this->value = pn.value;
    this->given = pn.given;
    this->middle = pn.middle;
    this->family = pn.family;
    this->prefix = pn.prefix;
    this->sufix = pn.sufix;
    this->delimiter = pn.delimiter;
    return *this;
  }

  /*!
   * \brief 'V' formatted-for-display version of the name
   */
  std::string value;
  /*!
   * \brief The given name component
   */

  std::optional<std::string> given;
  /*!
   * \brief The middle name component
   */
  std::optional<std::string> middle;
  /*!
   * \brief The family name component
   */
  std::optional<std::string> family;
  /*!
   * \brief A prefix component (e.g., "Dr.")
   */
  std::optional<std::string> prefix;
  /*!
   * \brief A suffix component (e.g., "Ph.D")
   */
  std::optional<std::string> sufix;
  /*!
   * \brief A delimiter character used to separate components
   */
  std::optional<std::string> delimiter;
};

/*!
 * \brief A dimensioned quantity expressing the result of measurement. It
 * consists of a real number value and a physical unit.
 */
template <typename T>
struct PQ {
  /*!
   * \brief Default constructor.
   */
  PQ() = default;
  /*!
   * \brief Copy constructor.
   * \param pq The PQ to copy.
   */
  PQ(const PQ& pq) { *this = pq; }
  /*!
   * \brief Overloading assignment operator.
   * \param pn The PQ's values to assign.
   * \return PQ
   */
  PQ& operator=(const PQ& pq) {
    if (this == &pq) {
      return *this;
    }
    this->value = pq.value;
    this->unit = pq.unit;
    return *this;
  }
  /*!
   * \brief The string representation of the value.
   */
  std::optional<T> value;
  /*!
   * \brief The units of measure for the value.
   */
  std::optional<std::string> unit;
};

/*!
 * \brief Data type is used to communicate a range of values with the same
 * units.
 */
template <typename T>
struct IVL {
  /*!
   * \brief Default constructor.
   */
  IVL() = default;
  /*!
   * \brief Copy constructor.
   * \param ivl The IVL to copy.
   */
  IVL(const IVL& ivl) { *this = ivl; }
  /*!
   * \brief Overloading assignment operator.
   * \param pn The IVL's values to assign.
   * \return IVL
   */
  IVL& operator=(const IVL& ivl) {
    if (this == &ivl) {
      return *this;
    }
    this->closed_low = ivl.closed_low;
    this->closed_high = ivl.closed_high;
    this->value_low = ivl.value_low;
    this->value_high = ivl.value_high;
    this->unit = ivl.unit;
    return *this;
  }
  /*!
   * \brief true if the lower bound is closed; false otherwise.
   */
  bool closed_low;
  /*!
   * \brief true if the upper bound is closed; false otherwise.
   */
  bool closed_high;
  /*!
   * \brief The lower bound of the interval.
   */
  std::optional<std::string> value_low;
  /*!
   * \brief The upper bound of the interval.
   */
  std::optional<std::string> value_high;
  /*!
   * \brief The unit of measure for the interval.
   */
  std::optional<std::string> unit;
};

/*!
 * \brief The CV struct consist of a code, display name, code system, and
 * original text. Used when a single code value must be sent.
 */
struct CV {
  /*!
   * \brief Default constructor
   */
  CV() = default;
  /*!
   * \brief Constructor with a code.
   * \param The code value.
   */
  CV(const std::string& code_value) : code(code_value) {}
  /*!
   * \brief Copy constructor.
   * \param cv The CV to copy.
   */
  CV(const CV& cv) { *this = cv; }
  /*!
   * \brief Overloading assignment operator.
   * \param cv The CV's values to assign.
   * \return CV
   */
  CV& operator=(const CV& cv) {
    if (this == &cv) {
      return *this;
    }
    this->code = cv.code;
    this->display_name = cv.display_name;
    this->code_set_id = cv.code_set_id;
    this->code_set_name = cv.code_set_name;
    this->code_set_version = cv.code_set_version;
    return *this;
  }
  /*!
   * \brief Overloading 'less than' operator.
   * \param second The CV value to compare with.
   * \return true if the inner code is less than the second's code.
   */
  bool operator<(const CV& second) const {
    return (this->code.compare(second.code) < 0);
  }
  /*!
   * \brief Overloading 'equal' operator.
   * \param second The CV value to compare with.
   * \return true if all the values are equal.
   */
  bool operator==(const CV& second) const {
    return (this->code == second.code &&
            this->display_name == second.display_name &&
            this->code_set_id == second.code_set_id &&
            this->code_set_name == second.code_set_name &&
            this->code_set_version == second.code_set_version);
  }

  /*!
   * \brief V' The value code
   */
  std::string code;
  /*!
   * \brief 'DN' Intended for display
   */
  std::optional<std::string> display_name;
  /*!
   * \brief 'S' OID denoting the authority this code set is registered to.
   */
  std::optional<std::string> code_set_id;
  /*!
   * \brief 'SN' The name of the registering authority for this
   * code set.
   */
  std::optional<std::string> code_set_name;
  /*!
   * \brief 'SV' Version of this code set.
   */
  std::optional<std::string> code_set_version;
};

/*!
 * \brief The CE struct consist of a coded value (CV) and,
 * std::optionally, codded
 * value(s) from other coding systems that identify the same concept. Used when
 * alternative codes may exist.
 */
struct CE : public CV {
  /*!
   * \brief Default constructor
   */
  CE() = default;
  /*!
   * \brief Constructor with a code.
   * \param The code value.
   */
  CE(const std::string& code_value) : CV(code_value) {}
  /*!
   * \brief Copy constructor.
   * \param ce The CE to copy.
   */
  CE(const CE& ce) : CV(ce) { *this = ce; }
  /*!
   * \brief Overloading assignment operator.
   * \param ce The CE's values to assign.
   * \return CE
   */
  CE& operator=(const CE& ce) {
    if (this == &ce) {
      return *this;
    }
    CV::operator=(ce);
    this->transliterations = ce.transliterations;
    return *this;
  }

  /*!
   * \brief Alternate representation to be communicated.
   */
  std::list<CV> transliterations;
};

/*!
 * \brief The AccessControl struct is a component of the Operator List message
 */
struct AccessControl {
  /*!
   * \brief The Method enum
   */
  enum class Method {
    ALL /**< The operator is granted permission to use all methods */
  };

  /*!
   * \brief The PermissionLevel enum
   */
  enum class PermissionLevel {
    UNDEFINED,
    SUPERVISOR,   /**< Full access to system. */
    KEY_OPERATOR, /**< Access to everything except to add new user and
                     change access level. */
    TRUSTED_USER, /**< Same as USER except can also accept failed QC. */
    USER,         /**< Can operate system to produce test results. */
    SERVICE,      /**< Allows access to special service diagnostics and
                     configuration modes. */
    TRAINING      /**< Can operate system but not report results. QC if run is
                     not added to QC statistics calculations. */
  };

  /*!
   * \brief Default constructor
   */
  AccessControl() = default;
  /*!
   * \brief Copy constructor.
   * \param access_control The AccessControl to copy.
   */
  AccessControl(const AccessControl& access_control) { *this = access_control; }
  /*!
   * \brief Overloading assignment operator.
   * \param access_control The AccessControl's values to assign.
   * \return AccessControl
   */
  AccessControl& operator=(const AccessControl& access_control) {
    if (this == &access_control) {
      return *this;
    }
    this->method = access_control.method;
    this->password = access_control.password;
    this->active_date = access_control.active_date;
    this->expiration_date = access_control.expiration_date;
    this->permission_lvl = access_control.permission_lvl;
    return *this;
  }

  /*!
   * \brief The Device's analytic method(s) that should be restricted by the
   * information in this object. Vendors that extend this table should use the
   * code system component of the CV data type to ensure unique values.
   */
  std::set<Method> method;
  /*!
   * \brief This user's password to access the described method. This field is
   * of type ED to allow communication of encrypred passwords.
   */
  std::optional<std::string> password;
  /*!
   * \brief The date after which this certificate is valid.
   */
  std::optional<std::tm> active_date;
  /*!
   * \brief The date on which this certificate expires.
   */
  std::optional<std::tm> expiration_date;
  /*!
   * \brief Code indicating what operations the user is allowed to perform.
   */
  std::optional<PermissionLevel> permission_lvl;
};

/*!
 * \brief The Ack struct is a component of the Acknowledgement message
 */
struct Ack {
  /*!
   * \brief The AckType enum
   */
  enum class AckType {
    AA, /**< Application Accept. The receiver assumes responsibility for the
           message contents. */
    AE  /**< Application Error. The receiver encountered an error processing the
           message. See errorDetail for more information. */
  };

  /*!
   * \brief The AckCode enum
   */
  enum class AckCode {
    SUCCESS = 0,
    SEQUENCE_ERROR = 100, /**< The message objects were not in the proper
                             order, or required objects are missing. */
    FIELD_MISSING = 101,  /**< A required field is missing from a segment. */
    DATA_TYPE_ERROR =
        102, /**< A message element is not of the type expected. */
    VALUE_NOT_FOUND = 103, /**< A code field was compared against the
                              corresponding table, and not match was found. */
    FIELD_NOT_SUPPORTED =
        200, /**< The field contained data of the wrong field value. */
    VERSION_ID_NOT_SUPPORTED = 201, /**< The Message version identifier
                                       (HDR.version_id) is not supported. */
    APP_INTERNAL_ERROR = 202        /**< A catch-all for internal errors not
                                       explicitly covered by other codes. */
  };

  /*!
   * \brief Default constructor
   */
  Ack() = default;
  /*!
   * \brief Copy constructor.
   * \param ack The ACK to copy.
   */
  Ack(const Ack& ack) { *this = ack; }
  /*!
   * \brief Overloading assignment operator.
   * \param ack The ACK's values to assign.
   * \return ACK
   */
  Ack& operator=(const Ack& ack) {
    if (this == &ack) {
      return *this;
    }
    this->type = ack.type;
    this->ack_control_id = ack.ack_control_id;
    this->note_txt = ack.note_txt;
    this->error_detail = ack.error_detail;
    return *this;
  }

  /*!
   * \brief The control ID of the message send that this message is in
   * acknowledgement of.
   */
  std::string ack_control_id;
  /*!
   * \brief A code indicating whether the associated message was accepted, was
   * in error, or was rejected.
   */
  std::optional<accm::CV> type;
  /*!
   * \brief Text describing the error condition. May be logged or presented to
   * user.
   */
  std::optional<std::string> note_txt;
  /*!
   * \brief A code indicating the type of error that occured.
   */
  std::optional<CV> error_detail;

  /*!
   * \brief Check if the given type is a valid ACK Type.
   * \param esc_code The type to check.
   * \return true if it is a valid code; false otherwise.
   */
  static bool IsValidType(const std::string& ack_type) {
    return ack_type == "AA" || ack_type == "AE";
  }

  /*!
   * \brief Check if the given code is a valid ACK code.
   * \param esc_code The code to check.
   * \return true if it is a valid code; false otherwise.
   */
  static bool IsValidCode(int ack_code) {
    return ack_code == static_cast<int>(AckCode::SUCCESS) ||
           ack_code == static_cast<int>(AckCode::SEQUENCE_ERROR) ||
           ack_code == static_cast<int>(AckCode::FIELD_MISSING) ||
           ack_code == static_cast<int>(AckCode::DATA_TYPE_ERROR) ||
           ack_code == static_cast<int>(AckCode::VALUE_NOT_FOUND) ||
           ack_code == static_cast<int>(AckCode::FIELD_NOT_SUPPORTED) ||
           ack_code == static_cast<int>(AckCode::VERSION_ID_NOT_SUPPORTED) ||
           ack_code == static_cast<int>(AckCode::APP_INTERNAL_ERROR);
  }
};

/*!
 * \brief The Directive struct is a component of the Directive message.
 */
struct Directive {
  /*!
   * \brief The DirectivesStandard enum
   */
  enum class DirectivesStandard {
    SET_TIME,         /**< Set Device Time */
    LOCK,             /**< Lockout */
    UNLOCK,           /**< Release Lockout */
    GOTO_STANDBY,     /**< Set Standby */
    GOTO_READY,       /**< Set Ready */
    START_CONTINUOUS, /**< Start Continuous */
    UNKOWN
  };

  /*!
   * \brief Default constructor.
   */
  Directive() : command(DirectivesStandard::UNKOWN) {}

  /*!
   * \brief Copy constructor.
   * \param directive The Directive to copy.
   */
  Directive(const Directive& directive) { *this = directive; }
  /*!
   * \brief Overloading assignment operator.
   * \param directive The Directive's values to assign.
   * \return Directive
   */
  Directive& operator=(const Directive& directive) {
    if (this == &directive) {
      return *this;
    }
    this->command = directive.command;
    return *this;
  }

  /*!
   * \brief A coded value representing a command for the Device to peform.
   */
  DirectivesStandard command;
};

/*!
 * \brief The ConnectionProfile struct is a structure encapsulates the
 * information related with the connection to the server.
 */
struct ConnectionProfile {
  /*!
   * \brief Default constructor.
   */
  ConnectionProfile() = default;
  /*!
   * \brief Copy constructor.
   * \param connection_profile The Device to copy.
   */
  ConnectionProfile(const ConnectionProfile& connection_profile) {
    *this = connection_profile;
  }
  /*!
   * \brief Overloading assignment operator.
   * \param connection_profile The ConnectionProfile's values to assign.
   * \return ConnectionProfile
   */
  ConnectionProfile& operator=(const ConnectionProfile& connection_profile) {
    if (this == &connection_profile) {
      return *this;
    }
    this->ip = connection_profile.ip;
    this->port = connection_profile.port;
    this->timeout = connection_profile.timeout;
    return *this;
  }

  /*!
   * \brief Observation reviewer's IP
   */
  std::string ip;
  /*!
   * \brief Observation reviewer's Port
   */
  unsigned short port;
  /*!
   * \brief Application-level timeout the Device uses, specified in
   * milliseconds.
   */
  std::chrono::milliseconds timeout;
};

/*!
 * \brief The DeviceStaticCapabilities struct is a component of the Hello
 * message
 */
struct DeviceStaticCapabilities {
  /*!
   * \brief The ConnectionProfile enum
   */
  enum class ConnectionProfileType {
    CS, /**< Continuous Synchronous */
    SA, /**< Synchronous Acknowledgement */
    AA  /**< Asynchronous Acknowledgement */
  };

  /*!
   * \brief The TopicSupported enum
   */
  enum class TopicSupported {
    OBS,      /**< Observations */
    D_EV,     /**< Device Events */
    DTV,      /**< Directives */
    OP_LST,   /**< Operator List */
    OP_LST_I, /**< Incremental Operator List */
    PT_LST,   /**< Patient List */
    PT_LST_I  /**< Incremental Patient List */
  };

  /*!
   * \brief Default constructor.
   */
  DeviceStaticCapabilities() = default;
  /*!
   * \brief Copy constructor.
   * \param capabilites The DeviceStaticCapabilities to copy.
   */
  DeviceStaticCapabilities(const DeviceStaticCapabilities& capabilites) {
    *this = capabilites;
  }
  /*!
   * \brief Overloading assignment operator.
   * \param capabilites The DeviceStaticCapabilities's values to assign.
   * \return DeviceStaticCapabilities.
   */
  DeviceStaticCapabilities& operator=(
      const DeviceStaticCapabilities& capabilities) {
    if (this == &capabilities) {
      return *this;
    }
    this->connection_profile = capabilities.connection_profile;
    this->topics_supported = capabilities.topics_supported;
    this->directives_supported = capabilities.directives_supported;
    this->max_message_size = capabilities.max_message_size;
    return *this;
  }
  /*!
   * \brief CIC messaging profile the Device supports.
   */
  std::optional<CV> connection_profile;
  /*!
   * \brief The message topics (beyond the minimum) supported.
   */
  std::optional<std::set<CV>> topics_supported;
  /*!
   * \brief The Directive commands the Device supports.
   */
  std::optional<std::set<CV>> directives_supported;
  /*!
   * \brief The maximum size message (in bytes) that the Device can handle.
   */
  std::optional<int> max_message_size;
};

/*!
 * \brief Alias for supported Topic.
 * \see DeviceStaticCapabilities#TOPIC_SUPPORTED
 */
typedef DeviceStaticCapabilities::TopicSupported Topic;

/*!
 * \brief The Device struct is a component of the Hello message.
 */
struct Device {
  /*!
   * \brief Default constructor.
   */
  Device(std::string id = "") : device_id(id) {}
  /*!
   * \brief Copy constructor.
   * \param device The Device to copy.
   */
  Device(const Device& device) { *this = device; }
  /*!
   * \brief Overloading assignment operator.
   * \param device The Device's values to assign.
   * \return Device
   */
  Device& operator=(const Device& device) {
    if (this == &device) {
      return *this;
    }
    this->device_id = device.device_id;
    this->vendor_id = device.vendor_id;
    this->model_id = device.model_id;
    this->serial_id = device.serial_id;
    this->manufacturer_name = device.manufacturer_name;
    this->hw_version = device.hw_version;
    this->sw_version = device.sw_version;
    this->device_name = device.device_name;
    this->vmd_id = device.vmd_id;
    this->vmd_name = device.vmd_name;
    this->static_capabilities = device.static_capabilities;
    this->connection_profile = device.connection_profile;
    return *this;
  }
  /*!
   * \brief Device identifier.
   */
  std::string device_id;
  /*!
   * \brief Vendor-specific unique identifier.
   */
  std::optional<std::string> vendor_id;
  /*!
   * \brief Vendor-specific unique model identifier.
   */
  std::optional<std::string> model_id;
  /*!
   * \brief Vendor-specific unique serial identifier.
   */
  std::optional<std::string> serial_id;
  /*!
   * \brief The manufacturer's corporate name.
   */
  std::optional<std::string> manufacturer_name;
  /*!
   * \brief The version number for the Device hardware.
   */
  std::optional<std::string> hw_version;
  /*!
   * \brief The software version number(s) for the Device.
   */
  std::optional<std::string> sw_version;
  /*!
   * \brief A convenient  name for the Device.
   */
  std::optional<std::string> device_name;
  /*!
   * \brief Text, noncoded name of "Virtual medical Device". This is to
   * support a Device with multiple Device capabiliy.
   */
  std::optional<std::string> vmd_id;
  /*!
   * \brief Institutionally unique, coded ID for Virtual Medical Device. This is
   * to support a Device with multiple Device capability.
   */
  std::optional<std::string> vmd_name;
  /*!
   * \brief All the static information about the device.
   */
  DeviceStaticCapabilities static_capabilities;
  /*!
   * \brief The information related to the Reviewer's connection.
   */
  ConnectionProfile connection_profile;
};

/*!
 * \brief The DeviceEvent struct is a component of the Device Events message
 */
struct DeviceEvent {
  /*!
   * \brief The SeverityLevel enum
   */
  enum class SeverityLevel {
    C, /**< Critical */
    N, /**< Note */
    W  /**< Warning */
  };

  /*!
   * \brief Default constructor.
   */
  DeviceEvent() = default;
  /*!
   * \brief Copy constructor.
   * \param device_event The DeviceEvent to copy.
   */
  DeviceEvent(const DeviceEvent& device_event) { *this = device_event; }
  /*!
   * \brief Overloading assignment operator.
   * \param device_event The DeviceEvent's values to assign.
   * \return DeviceEvent.
   */
  DeviceEvent& operator=(const DeviceEvent& device_event) {
    if (this == &device_event) {
      return *this;
    }
    this->description = device_event.description;
    this->event_dttm = device_event.event_dttm;
    this->severity = device_event.severity;
    return *this;
  }

  /*!
   * \brief Free text description of the event.
   */
  std::string description;
  /*!
   * \brief Time the event occurred.
   */
  time_t event_dttm;
  /*!
   * \brief An indication of the level of operator intervention.
   */
  SeverityLevel severity;
};

/*!
 * \brief The DeviceStatus struct is a component of the Device Status message.
 */
struct DeviceStatus {
  /*!
   * \brief The DeviceCondition enum
   */
  enum class DeviceCondition {
    BUSY,   /**< The Device is in the process of running a test or is otherwise
               occupied and unable to start a new test. */
    LOCKED, /**< The Device has been locked so that it cannot be used to run
               tests */
    PARTIAL_LOCKED, /**< One or more analytic tests have been disabled for
                       this
                       Device */
    READY,          /**< The Device is ready to process tests */
    STANDBY, /**< The Device is capable of running a new test once it has been
                awakened from this 'idle' mode */
    UNKNOWN = -1
  };

  /*!
   * \brief Default constructor.
   */
  DeviceStatus() = default;
  /*!
   * \brief Copy constructor.
   * \param device_status The DeviceStatus to copy.
   */
  DeviceStatus(const DeviceStatus& device_status) { *this = device_status; }
  /*!
   * \brief Overloading assignment operator.
   * \param terminate The Terminate's values to assign.
   * \return Terminate.
   */
  DeviceStatus& operator=(const DeviceStatus& device_status) {
    if (this == &device_status) return *this;
    this->new_observations = device_status.new_observations;
    this->new_events = device_status.new_events;
    this->condition = device_status.condition;
    this->status_timestamp = device_status.status_timestamp;
    this->observations_update = device_status.observations_update;
    this->events_update = device_status.events_update;
    this->operators_update = device_status.operators_update;
    this->patients_update = device_status.patients_update;
    return *this;
  }

  /*!
   * \brief The number of observations the Device has to report.
   */
  int new_observations;
  /*!
   * \brief The number of events since the last sync.
   */
  std::optional<int> new_events;
  /*!
   * \brief The current level of readiness of the Device.
   */
  std::optional<CV> condition;
  /*!
   * \brief The time that this status information was observed.
   */
  time_t status_timestamp;
  /*!
   * \brief The time the Device last uploaded observations (i.e., successfully
   * completed the Observations Topic).
   */
  std::optional<time_t> observations_update;
  /*!
   * \brief The time the Device last successfully completed the Device Events
   * Topic.
   */
  std::optional<time_t> events_update;
  /*!
   * \brief The time the Device last successfully completed the Operator List
   * Topic.
   */
  std::optional<time_t> operators_update;
  /*!
   * \brief The time the Device last successfully completed the patient List
   * Topic.
   */
  std::optional<time_t> patients_update;
};

/*!
 * \brief Alias for Device Condition
 * \see DeviceStatus#DEVICE_CONDITION
 */
typedef DeviceStatus::DeviceCondition Status;

/*!
 * \brief The EndOfTopic struct used in the End of Topic message
 */
struct EndOfTopic {
  /*!
   * \brief The Code enum
   */
  enum class Code {
    EVS, /**< End of the Device Events Topic */
    OBS, /**< End of the Observations Topic */
    OPL, /**< End of the Operator List Topic */
    PTL  /**< End of the Patient List Topic */
  };

  /*!
   * \brief Default constructor.
   */
  EndOfTopic() = default;
  /*!
   * \brief Copy constructor.
   * \param end_of_topic The EndOfTopic to copy.
   */
  EndOfTopic(const EndOfTopic& end_of_topic) { *this = end_of_topic; }
  /*!
   * \brief Overloading assignment operator.
   * \param end_of_topic The EndOfTopic's values to assign.
   * \return EndOfTopic.
   */
  EndOfTopic& operator=(const EndOfTopic& end_of_topic) {
    if (this == &end_of_topic) {
      return *this;
    }
    this->topic = end_of_topic.topic;
    this->update = end_of_topic.update;
    this->eot_control = end_of_topic.eot_control;
    return *this;
  }

  /*!
   * \brief A coded for the Topic that has just been completed. Vendors may
   * extend this list to accommodate vendor-specific message Topics, using the
   * code system attribute of the CV data type to ensure uniqueness.
   */
  CV topic;
  /*!
   * \brief A timestamp provided to indicate the date and time that the
   * current
   * list was valid.
   */
  std::optional<time_t> update;
  /*!
   * \brief A message control code from the header of the message to which
   * this EOT is a response.
   */
  std::optional<std::string> eot_control;
};

/*!
 * \brief The Escape struct is component of the Escape message.
 */
struct Escape {
  /*!
   * \brief The Code enum
   */
  enum class Code {
    OTH, /**< Other reason */
    TOP, /**< Unsupported Topic */
    CNC  /**< Cannot complete Topic at this time */
  };

  /*!
   * \brief Default constructor.
   */
  Escape() = default;
  /*!
   * \brief Copy constructor.
   * \param escape The Escape to copy.
   */
  Escape(const EndOfTopic& escape) { *this = escape; }
  /*!
   * \brief Overloading assignment operator.
   * \param escape The Escape's values to assign.
   * \return Escape.
   */
  Escape& operator=(const Escape& escape) {
    if (this == &escape) {
      return *this;
    }
    this->esc_control_id = escape.esc_control_id;
    this->detail = escape.detail;
    this->note = escape.note;
    return *this;
  }

  /*!
   * \brief The message control code from the Header of the message to which
   * this Escape is a response.
   */
  std::string esc_control_id;
  /*!
   * \brief A code indicating the reason for the Escape message.
   */
  CV detail;
  /*!
   * \brief Further explanatory text that may be logged or displayed by the
   * Receiver.
   */
  std::optional<std::string> note;

  /*!
   * \brief Check if the given code is a valid Escape code.
   * \param esc_code The code to check.
   * \return true if it is a valid code; false otherwise.
   */
  static bool IsValidCode(const std::string& esc_code) {
    return esc_code == "OTH" || esc_code == "TOP" || esc_code == "CNC";
  }
};

/*!
 * \brief The Header struct mandatory component of every message.
 */
struct Header {
  /*!
   * \brief The MsgType enum
   */
  enum class MsgType {
    REQ_R01,    /**< Request */
    ACK_R01,    /**< Acknowledgement */
    HEL_R01,    /**< Hello */
    OBS_R01,    /**< Patient Observations */
    OBS_R02,    /**< Non-patient Observations */
    EVS_R01,    /**< Device Events */
    DST_R01,    /**< Device Status */
    DTV_R01,    /**< Basic Directive */
    DTV_R02,    /**< Complex Directive */
    DTV_VENDOR, /**< Vendor-specific Directive */
    OPL_R01,    /**< Operator List (complete) */
    OPL_R02,    /**< Operator List (incremental) */
    PTL_R01,    /**< Patient List (complete) */
    PTL_R02,    /**< Patient List (incremental) */
    EOT_R01,    /**< End of Topic */
    ESC_R01,    /**< Escape */
    END_R01     /**< Terminate */
  };

  /*!
   * \brief Default constructor.
   */
  Header() : version_id("POCT1") {}
  /*!
   * \brief Copy constructor.
   * \param header The Header to copy.
   */
  Header(const Header& header) { *this = header; }
  /*!
   * \brief Overloading assignment operator.
   * \param header The Header's values to assign.
   * \return Header
   */
  Header& operator=(const Header& header) {
    if (this == &header) {
      return *this;
    }
    this->message_type = header.message_type;
    this->control_id = header.control_id;
    this->version_id = header.version_id;  // Always POCT1
    this->creation_dttm = header.creation_dttm;
    this->encoding_chars = header.encoding_chars;
    return *this;
  }
  /*!
   * \brief A string guaranteed to uniquely identify this message throughout
   * the
   * conversation.
   */
  std::string control_id;
  /*!
   * \brief Set to "POCT1" for all messages that adhere to this standard.
   */
  std::string version_id;
  /*!
   * \brief The Sender's time when the message was sent.
   */
  time_t creation_dttm;
  /*!
   * \brief A code made up of the message name and trigger value. Values for
   * this field may be found in the description of each message.
   */
  std::optional<CV> message_type;
  /*!
   * \brief A list of special characters used to encode components of string
   * fields. This filed takes the form of a four-character string. The default
   * value for the string is "^~\&".
   * The format and meaning of this string is borrowed from HL7 v2.4 Section 2.8
   * - Message Delimiters.
   */
  std::optional<std::string> encoding_chars;
};

/*!
 * \brief The Note struct used in several message models, including
 * Observations
 * and Operator List. It's also used to extend for some message extensions to
 * qualify the reported data
 */
struct Note {
  enum class MsgType {
    OPERATOR_COMMENT, /**< Operator Comment */
    ABNORMAL_FLAG     /**< Abnormal Flag*/
  };

  /*!
   * \brief Default constructor.
   */
  Note() : type_cd(MsgType::OPERATOR_COMMENT) {}
  /*!
   * \brief Copy constructor.
   * \param note The Note to copy.
   */
  Note(const Note& note) { *this = note; }
  /*!
   * \brief Overloading assignment operator.
   * \param note The Note's values to assign.
   * \return Note
   */
  Note& operator=(const Note& note) {
    if (this == &note) {
      return *this;
    }
    this->type_cd = note.type_cd;
    this->text = note.text;
    this->code = note.code;
    return *this;
  }

  /*!
   * \brief Qualifies which is the use of this specific Note instance.
   */
  MsgType type_cd;

  /*!
   * \brief The string's contents are dependent on the context in which the Note
   * object is used.
   */
  std::string text;

  /*!
   * \brief Coded value that identifies the abnormal flag reported in this
   * Note.
   */
  std::optional<std::string> code;
};

/*!
 * \brief The Observation struct is a Component of the Observations message.
 */
struct Observation {
  /*!
   * \brief The Qualitative enum
   */
  enum class Qualitative {
    L,  /**< Low */
    H,  /**< High */
    LL, /**< Very low */
    HH, /**< Very high */
    N,  /**< Normal */
    A,  /**< Abnormal */
    AA, /**< Very abnormal (analogous to panic limits for numeric units) */
    U,  /**< Significant change up */
    D,  /**< Significant change down */
    B,  /**< Better - use when direction not relevant */
    W   /**< Worse - use when direction not relevant */
  };

  /*!
   * \brief The Method enum
   */
  enum class Method {
    C, /**< Calculated */
    D, /**< Default */
    E, /**< Estimated */
    I, /**< Input - The value was externally input to the Device */
    M, /**< Measured */
    U, /**< Unknown - It is unkwonw from where the value came */
  };

  /*!
   * \brief The Status enum
   */
  enum class Status {
    A, /**< Accepted */
    D, /**< Discarded */
    U, /**< Unknown */
    X  /**< Rejected */
  };

  /*!
   * \brief The Interpretation enum
   */
  enum class Interpretation {
    L,       /**< Below low normal */
    H,       /**< Above high normal */
    LL,      /**< Below lower panic limits */
    HH,      /**< Above upper panic limits */
    LESS,    /**< Below absolute low-off instrument scale */
    GREATER, /**< Above absolute high-off instrument scale */
    N,       /**< Normal (applies to nonnumeric results) */
    A,       /**< Abnormal (appliest to nonnumeric results) */
    AA,      /**< Very abnormal (applies to nonnumeric units, analogous to panic
                limits for numeric units) */
    null,    /**< No range defined, or normal ranges don't apply */
    U,       /**< Significant change up */
    D,       /**< Significant change down */
    B,       /**< Better - use when direction not relevant */
    W,       /**< Worse - use when direction not relevant */
  };

  /*!
   * \brief Default constructor.
   */
  // Observation() : method(Method::U) {}
  Observation() = default;
  /*!
   * \brief Copy constructor.
   * \param observation The Observation to copy.
   */
  Observation(const Observation& observation) { *this = observation; }
  /*!
   * \brief Overloading assignment operator.
   * \param observation The Observation's values to assign.
   * \return Observation
   */
  Observation& operator=(const Observation& observation) {
    if (this == &observation) {
      return *this;
    }
    this->observation_id = observation.observation_id;
    this->value = observation.value;
    this->qualitative_value = observation.qualitative_value;
    this->method = observation.method;
    this->status = observation.status;
    this->interpretation = observation.interpretation;
    this->normal_lo_hi_limit = observation.normal_lo_hi_limit;
    this->critical_lo_hi_limit = observation.critical_lo_hi_limit;
    this->notes = observation.notes;
    return *this;
  }

  /*!
   * \brief The Unique identifier for the result. Preferably, this code will
   * come from LOINC code set; howevert, local codes may be used.
   */
  CE observation_id;
  /*!
   * \brief The observation result, if expressed quantitatively (numerical
   * value
   * with units).
   */
  std::optional<PQ<std::string>> value;
  /*!
   * \brief The observation result, if expressed qualitatively.
   */
  std::optional<CV> qualitative_value;
  /*!
   * \brief How was this value determined? Measured? Calculated?
   */
  CV method;
  /*!
   * \brief e.g., Accepted, Rejected.
   */
  std::optional<CV> status;
  /*!
   * \brief Commonly referred to as 'abnormal flags'.
   */
  std::optional<CV> interpretation;
  /*!
   * \brief The low and high limit range for a normal test.
   */
  std::optional<IVL<std::string>> normal_lo_hi_limit;
  /*!
   * \brief The low and high limit range outside which clinical review is
   * required.
   */
  std::optional<IVL<std::string>> critical_lo_hi_limit;
  /*!
   * \brief notes
   */
  std::list<Note> notes;

  /*!
   * \brief Check if the given code is a valid Method code.
   * \param method The code to check.
   * \return true if it is a valid code; false otherwise.
   */
  static bool IsValidMethod(const std::string& method) {
    return method == "C" || method == "D" || method == "E" || method == "I" ||
           method == "M" || method == "U";
  }

  /*!
   * \brief Check if the given code is a valid Qualitate Value code.
   * \param value The code to check.
   * \return true if it is a valid code; false otherwise.
   */
  static bool IsQualitativeValue(const std::string& value) {
    return value == "L" || value == "H" || value == "LL" || value == "HH" ||
           value == "N" || value == "A" || value == "AA" || value == "U" ||
           value == "D" || value == "B" || value == "W";
  }

  /*!
   * \brief Check if the given code is a valid Status code.
   * \param status The code to check.
   * \return true if it is a valid code; false otherwise.
   */
  static bool IsValidStatus(const std::string& status) {
    return status == "A" || status == "D" || status == "U" || status == "X";
  }

  /*!
   * \brief Check if the given code is a valid Interpretation code.
   * \param intepretation The code to check.
   * \return true if it is a valid code; false otherwise.
   */
  static bool IsValidInterpretation(const std::string& inter) {
    return inter == "L" || inter == "H" || inter == "LL" || inter == "HH" ||
           inter == "LESS" || inter == "GREATER" || inter == "N" ||
           inter == "A" || inter == "AA" || inter == "null" || inter == "U" ||
           inter == "D" || inter == "B" || inter == "W";
  }
};

/*!
 * \brief The Operator struct is a component of both the Observations and the
 * Operator List messages.
 */
struct Operator {
  /*!
   * \brief The Action enum
   */
  enum class Action {
    I, /**< Insert the specified entries into the associated list. */
    D  /**< Delete the specified entries from the associated list. */
  };

  /*!
   * \brief Default constructor.
   */
  Operator() = default;
  /*!
   * \brief Copy constructor.
   * \param opt The Operator to copy
   */
  Operator(const Operator& opt) { *this = opt; }
  /*!
   * \brief Overloading assignment operator.
   * \param opt The Operator's values to assign.
   * \return Operator
   */
  Operator& operator=(const Operator& opt) {
    if (this == &opt) {
      return *this;
    }
    this->operator_id = opt.operator_id;
    this->action = opt.action;
    this->name = opt.name;
    return *this;
  }

  /*!
   * \brief The unique identifier for the operator of the Device.
   */
  accm::CV operator_id;

  /*!
   * \brief Usefull in incremental Operator List topic. Not defined for
   * complete
   * updates.
   */
  std::optional<Action> action;

  /*!
   * \brief The name of the operator who performed the test.
   */
  std::optional<PN> name;
};

/*!
 * \brief The Order struct is a component of the Observation message.
 */
struct Order {
  /*!
   * \brief Default constructor.
   */
  Order() = default;
  /*!
   * \brief Copy constructor.
   * \param order The Order to copy.
   */
  Order(const Order& order) { *this = order; }
  /*!
   * \brief Overloading assignment operator.
   * \param order The Order's values to assign.
   * \return Patient
   */
  Order& operator=(const Order& order) {
    if (this == &order) {
      return *this;
    }
    this->universal_service_id = order.universal_service_id;
    this->ordering_provider_id = order.ordering_provider_id;
    this->order_id = order.order_id;
    return *this;
  }

  /*!
   * \brief Identifies the service provided by these observations.
   */
  CE universal_service_id;
  /*!
   * \brief An identifier that uniquely identifies the provider who ordered
   * this
   * service.
   */
  std::optional<std::string> ordering_provider_id;
  /*!
   * \brief An identifier that uniquely identifies this service instance. This
   * filed may contain an order id, accession number, or other such
   * identifier.
   */
  std::optional<CV> order_id;
};

/*!
 * \brief The Patient struct is a component of both Observation and the
 * Patient
 * List.
 */
struct Patient {
  /*!
   * \brief The Gender enum
   */
  enum class Gender {
    F, /**< Female */
    M, /**< Male */
    O, /**< Other */
    U, /**< Unknown */
    A, /**< Ambiguous */
    N  /**< Not applicable */
  };

  /*!
   * \brief Default constructor.
   */
  Patient() = default;
  /*!
   * \brief Copy constructor.
   * \param patient The Patient to copy.
   */
  Patient(const Patient& patient) { *this = patient; }
  /*!
   * \brief Overloading assignment operator.
   * \param patient The Patient's values to assign.
   * \return Patient
   */
  Patient& operator=(const Patient& Patient) {
    if (this == &Patient) {
      return *this;
    }
    this->patient_id = Patient.patient_id;
    this->location = Patient.location;
    this->name = Patient.name;
    this->birth_date = Patient.birth_date;
    this->gender = Patient.gender;
    this->weight = Patient.weight;
    this->height = Patient.height;
    return *this;
  }

  /*!
   * \brief The unique identifier for the Patient.
   */
  std::string patient_id;
  /*!
   * \brief The location of the Patient when the specimen was drawn.
   */
  std::optional<std::string> location;
  /*!
   * \brief The name of the patient.
   */
  std::optional<PN> name;
  /*!
   * \brief The patient's date of birth.
   */
  std::optional<std::tm> birth_date;
  /*!
   * \brief The patient's gender.
   */
  std::optional<accm::CV> gender;
  /*!
   * \brief The patient's weight.
   */
  std::optional<PQ<std::string>> weight;
  /*!
   * \brief The patient's height.
   */
  std::optional<PQ<std::string>> height;

  static bool IsValidGender(const std::string& gender) {
    return gender == "F" || gender == "M" || gender == "O" || gender == "U" ||
           gender == "A" || gender == "N";
  }
};

/*!
 * \brief The Reagent struct is a component of the Observations message.
 */
struct Reagent {
  /*!
   * \brief Default constructor.
   */
  Reagent() = default;
  /*!
   * \brief Copy constructor.
   * \param reagent The Reagent to copy.
   */
  Reagent(const Reagent& reagent) { *this = reagent; }
  /*!
   * \brief Overloading assignment operator.
   * \param reagent The Reagent's values to assign.
   * \return Reagent
   */
  Reagent& operator=(const Reagent& reagent) {
    if (this == &reagent) {
      return *this;
    }
    this->name = reagent.name;
    this->lot_number = reagent.lot_number;
    this->expiration_date = reagent.expiration_date;
    return *this;
  }
  /*!
   * \brief The manufacturer's name for the reagent.
   */
  std::string name;
  /*!
   * \brief The lot number of the reagent used.
   */
  CV lot_number;
  /*!
   * \brief The date past which the reagent should not be used.
   */
  std::tm expiration_date;
};

/*!
 * \brief The Request struct is a component of the Request messages.
 */
struct Request {
  /*!
   * \brief The Type enum
   */
  enum class Type {
    ROBS, /**< Request Observations */
    RDEV  /**< Request Device Events */
  };

  /*!
   * \brief Default constructor.
   */
  Request() = default;
  /*!
   * \brief Copy constructor.
   * \param request The Request to copy.
   */
  Request(const Request& request) { *this = request; }
  /*!
   * \brief Overloading assignment operator.
   * \param request The Request's values to assign.
   * \return Request
   */
  Request& operator=(const Request& request) {
    if (this == &request) {
      return *this;
    }
    this->type = request.type;
    return *this;
  }

  /*!
   * \brief A code denoting the information requested.
   */
  CV type;

  static bool IsValidCode(const std::string& req_code) {
    return req_code == "ROBS" || req_code == "RDEV";
  }
};

/*!
 * \brief The ControlCalibration struct is a component of the Observations
 * message.
 */
struct ControlCalibration {
  /*!
   * \brief Default constructor.
   */
  ControlCalibration() = default;

  /*!
   * \brief Copy constructor.
   * \param control_calibration The ControlCalibration to copy.
   */
  ControlCalibration(const ControlCalibration& control_calibration) {
    *this = control_calibration;
  }
  /*!
   * \brief Overloading assignment operator.
   * \param control_calibration The ControlCalibration's values to assign.
   * \return ControlCalibration
   */
  ControlCalibration& operator=(const ControlCalibration& control_calibration) {
    if (this == &control_calibration) {
      return *this;
    }
    this->name = control_calibration.name;
    this->lot_number = control_calibration.lot_number;
    this->expiration_date = control_calibration.expiration_date;
    this->level = control_calibration.level;
    this->cal_ver_repetition = control_calibration.cal_ver_repetition;
    return *this;
  }

  /*!
   * \brief QC/Calbration: Vendor.
   */
  std::string name;
  /*!
   * \brief QC/Calibration: The (vendor-specific) lot number of the
   * control/calibration material.
   */
  std::optional<CV> lot_number;
  /*!
   * \brief QC/Calibration: The expiration date for the reagent used for this
   * test.
   */
  std::optional<std::tm> expiration_date;
  /*!
   * \brief QC: The level for this QC test (e.g., 'hi', 'lo', '1', '2').
   * Calibration: The level for this calibration verification test (e.g.,
   * 0,1,2,3..n).
   */
  std::optional<CV> level;
  /*!
   * \brief QC: Not Applicable.
   * Calibration: If tests within a linearity sequence are repeated at a given
   * level, this field indicates the repetition count for this particular
   * test.
   */
  std::optional<int> cal_ver_repetition;
};

/*!
 * \brief The Specimen struct is a component of the Observations message.
 */
struct Specimen {
  /*!
   * \brief The Source enum
   */
  enum class Source {
    BE,    /**< Bilateral Ears */
    OU,    /**< Bilateral Eyes */
    BN,    /**< Bilateral Nares */
    BU,    /**< Buttock */
    CT,    /**< Chest Tube */
    LA,    /**< Left Arm */
    LAC,   /**< Left Anterior Chest */
    LACF,  /**< Left Antecubital Fossa */
    LD,    /**< Left Deltoid */
    LE,    /**< Left Ear */
    LEJ,   /**< Left External Jugular */
    OS,    /**< Left Eye */
    LF,    /**< Left Foot */
    LG,    /**< Left Gluteus Medius */
    LH,    /**< Left Hand */
    LIJ,   /**< Left Internal Jugular */
    LLAQ,  /**< Left Lower Abd Quadrant */
    LLFA,  /**< Left Lower Forearm */
    LMFA,  /**< Left Mid Forearm */
    LN,    /**< Left Naris */
    LPC,   /**< Left Posterior Chest */
    LSC,   /**< Left Subclavian */
    LT,    /**< Left Thigh */
    LUA,   /**< Left Upper Arm */
    LUAQ,  /**< Left Upper Abd Quadrant */
    LUFA,  /**< Left Upper Forearm */
    LVG,   /**< Left Ventragluteal */
    LVL,   /**< Left Vastus Lateralis */
    NB,    /**< Nebulized */
    PA,    /**< Perianal */
    PERIN, /**< Perineal */
    RA,    /**< Right Arm */
    RAC,   /**< Right Anterior Chest */
    RACF,  /**< Right Antecubital Fossa */
    RD,    /**< Right Deltoid */
    RE,    /**< Right Ear */
    REJ,   /**< Right External Jugular */
    OD,    /**< Right Eye */
    RF,    /**< Right Foot */
    RG,    /**< Right Gluteus Medius */
    RH,    /**< Right Hand */
    RIJ,   /**< Right Internal Jugular */
    RLAQ,  /**< Right Lower Abd Quadrant */
    RLFA,  /**< Right Lower Forearm */
    RMFA,  /**< Right Mid Forearm */
    RN,    /**< Right Naris */
    RPC,   /**< Right Posterior Chest */
    RSC,   /**< Right Subclavian */
    RT,    /**< Right Thigh */
    RUA,   /**< Right Upper Arm */
    RUAQ,  /**< Right Upper Abd Quadrant */
    RUFA,  /**< Right Upper Forearm */
    RVL,   /**< Right Vastus Lateralis*/
    RVG    /**< Right Ventragluteal */
  };

  /*!
   * \brief The Type enum
   */
  enum class Type {
    ABS,   /**< Abscess */
    AMN,   /**< Amniotic fluid */
    ASP,   /**< Aspirate */
    BPH,   /**< Basophils */
    BIFL,  /**< Bile fluid */
    BLDA,  /**< Blood arterial */
    BBL,   /**< Blood bag */
    BLDC,  /**< Blood capilary */
    BLMV,  /**< Blood mixed venous */
    BPU,   /**< Blood product unit */
    BLDV,  /**< Blood venous */
    BON,   /**< Bone */
    BRTH,  /**< Breath (use EXHLD) */
    BRO,   /**< Bronchial */
    BRN,   /**< Burn */
    CALC,  /**< Calculus (=Stone) */
    CDM,   /**< Cardiac muscle */
    CNL,   /**< Cannula */
    CTP,   /**< Catheter tip */
    CSF,   /**< Cerebral spinal fluid */
    CVM,   /**< Cervical mucus */
    CVX,   /**< Cervix */
    COL,   /**< Colostrum */
    BLDCO, /**< Cord blood */
    CNJT,  /**< Conjunctiva */
    CUR,   /**< Curettage */
    CYST,  /**< Cyst */
    DIAF,  /**< Dialysis fluid */
    DOSE,  /**< Dose med or substance */
    DRN,   /**< Drain */
    DUFL,  /**< Duodenal fluid */
    EAR,   /**< Ear */
    EARW,  /**< Ear wax (cerumen) */
    ELT,   /**< Electrode */
    ENDC,  /**< Endocardium */
    ENDM,  /**< Endometrium */
    EOS,   /**< Eosinophils */
    RBC,   /**< Erythrocytes */
    EYE,   /**< Eye */
    EXG,   /**< Exhaled gas (=breath) */
    FIB,   /**< Fibroblasts */
    FLT,   /**< Filter */
    FIST,  /**< Fistula */
    FLU,   /**< Body fluid, unsp */
    GAS,   /**< Gas */
    GAST,  /**< Gastric fluid/contents */
    GEN,   /**< Genital */
    GENC,  /**< Genital cervix */
    GENL,  /**< Genital lochia */
    GENV,  /**< Genital vaginal */
    HAR,   /**< Hair */
    IHG,   /**< Inhaled gas */
    IT,    /**< Intubation tube */
    ISLT,  /**< Isolate */
    LAM,   /**< Lamella */
    WBC,   /**< Leukocytes */
    LN,    /**< Line */
    LNA,   /**< Line arterial */
    LNV,   /**< Line venous */
    LIQ,   /**< Liquid NOS */
    LYM,   /**< Lymphocytes */
    MAC,   /**< Macrophages */
    MAR,   /**< Marrow */
    MEC,   /**< Meconium */
    MBLD,  /**< Menstrual blood */
    MLK,   /**< Milk */
    MILK,  /**< Breast milk */
    NAIL,  /**< Nail */
    NOS,   /**< Nose (nasal passage) */
    ORH,   /**< Other */
    PAFL,  /**< Pancreatic fluid */
    PAT,   /**< Patient */
    PRT,   /**< Peritoneal fluid/ascites */
    PLC,   /**< Placenta */
    PLAS,  /**< Plasma */
    PLB,   /**< Plasma bag */
    PLR,   /**< Pleural fluid (thoracentesis fld) */
    PMN,   /**< Polymorphonuclear neutrophils */
    PPP,   /**< Platelet poor plasma */
    PRP,   /**< Platelet rich plasma */
    PUS,   /**< Pus */
    RT,    /**< Route of medicine */
    SAL,   /**< Saliva */
    SMN,   /**< Seminal fluid*/
    SER,   /**< Serum */
    SKN,   /**< Skin */
    SKM,   /**< Skeletal muscle */
    SPRM,  /**< Spermatozoa */
    SPT,   /**< Sputum */
    SPTC,  /**< Sputum - coughed */
    SPTT,  /**< Sputum - tracheal aspirate */
    STON,  /**< Stone (use CALC) */
    STL,   /**< Stool = Fecal */
    SWT,   /**< Sweat */
    SNV,   /**< Synovial fluid (Joint fluid) */
    TEAR,  /**< Tears */
    THRT,  /**< Throat */
    THRB,  /**< Thrombocyte (platelet) */
    TISS,  /**< Tissue */
    TISG,  /**< Tissue gall bladder */
    TLGI,  /**< Tissue large intestine */
    TLNG,  /**< Tissue lung */
    TISPL, /**< Tissue placenta */
    TSMI,  /**< Tissue small intestine */
    TISU,  /**< Tissue ulcer */
    TUB,   /**< Tube NOS */
    ULC,   /**< Ulcer */
    UMB,   /**< Umbilical blood */
    UMED,  /**< Unknown medicine */
    URTH,  /**< Urethra */
    UR,    /**< Urine */
    URC,   /**< Urine clean catch */
    URT,   /**< Urine catheter */
    URNS,  /**< Urine sediment */
    USUB,  /**< Unknown substance */
    VITF,  /**< Vitreous fluid */
    VOM,   /**< Vomitus */
    BLD,   /**< Whole blood */
    BDY,   /**< Whole body */
    WAT,   /**< Water */
    WICK,  /**< Wick */
    WND,   /**< Wound */
    WNDA,  /**< Wound abscess */
    WNDE,  /**< Wound exudate */
    WNDD   /**< Wound drainage */
  };

  /*!
   * \brief Default constructor.
   */
  Specimen() = default;

  /*!
   * \brief Copy constructor.
   * \param specimen The Specimen to copy.
   */
  Specimen(const Specimen& specimen) { *this = specimen; }
  /*!
   * \brief Overloading assignment operator.
   * \param specimen The Specimen's values to assign.
   * \return
   */
  Specimen& operator=(const Specimen& specimen) {
    if (this == &specimen) {
      return *this;
    }
    this->specimen_dttm = specimen.specimen_dttm;
    this->specimen_id = specimen.specimen_id;
    this->source = specimen.source;
    this->type = specimen.type;
    return *this;
  }

  /*!
   * \brief Time the specimen was drawn.
   */
  time_t specimen_dttm;
  /*!
   * \brief The code identifying the specimen.
   */
  std::optional<CV> specimen_id;
  /*!
   * \brief Location of the specimen, Arterial, Left Arm, etc.
   */
  std::optional<CE> source;
  /*!
   * \brief The type of specimen.
   */
  std::optional<CE> type;

  static bool IsValidSource(const std::string& source) {
    return source == "BE" || source == "OU" || source == "BN" ||
           source == "BU" || source == "CT" || source == "LA" ||
           source == "LAC" || source == "LACF" || source == "LD" ||
           source == "LE" || source == "LEJ" || source == "OS" ||
           source == "LF" || source == "LG" || source == "LH" ||
           source == "LIJ" || source == "LLAQ" || source == "LLFA" ||
           source == "LMFA" || source == "LN" || source == "LPC" ||
           source == "LSC" || source == "LT" || source == "LUA" ||
           source == "LUAQ" || source == "LUFA" || source == "LVG" ||
           source == "LVL" || source == "NB" || source == "PA" ||
           source == "PERIN" || source == "RA" || source == "RAC" ||
           source == "RACF" || source == "RD" || source == "RE" ||
           source == "REJ" || source == "OD" || source == "RF" ||
           source == "RG" || source == "RH" || source == "RIJ" ||
           source == "RLAQ" || source == "RLFA" || source == "RMFA" ||
           source == "RN" || source == "RPC" || source == "RSC" ||
           source == "RT" || source == "RUA" || source == "RUAQ" ||
           source == "RUFA" || source == "RVL" || source == "RVG";
  }

  static bool IsValidType(const std::string& type) {
    return type == "ABS" || type == "AMN" || type == "ASP" || type == "BPH" ||
           type == "BIFL" || type == "BLDA" || type == "BBL" ||
           type == "BLDC" || type == "BLMV" || type == "BPU" ||
           type == "BLDV" || type == "BON" || type == "BRTH" || type == "BRO" ||
           type == "BRN" || type == "CALC" || type == "CDM" || type == "CNL" ||
           type == "CTP" || type == "CSF" || type == "CVM" || type == "CVX" ||
           type == "COL" || type == "BLDCO" || type == "CNJT" ||
           type == "CUR" || type == "CYST" || type == "DIAF" ||
           type == "DOSE" || type == "DRN" || type == "DUFL" || type == "EAR" ||
           type == "EARW" || type == "ELT" || type == "ENDC" ||
           type == "ENDM" || type == "EOS" || type == "RBC" || type == "EYE" ||
           type == "EXG" || type == "FIB" || type == "FLT" || type == "FIST" ||
           type == "FLU" || type == "GAS" || type == "GAST" || type == "GEN" ||
           type == "GENC" || type == "GENL" || type == "GENV" ||
           type == "HAR" || type == "IHG" || type == "IT" || type == "ISLT" ||
           type == "LAM" || type == "WBC" || type == "LN" || type == "LNA" ||
           type == "LNV" || type == "LIQ" || type == "LYM" || type == "MAC" ||
           type == "MAR" || type == "MEC" || type == "MBLD" || type == "MLK" ||
           type == "MILK" || type == "NAIL" || type == "NOS" || type == "ORH" ||
           type == "PAFL" || type == "PAT" || type == "PRT" || type == "PLC" ||
           type == "PLAS" || type == "PLB" || type == "PLR" || type == "PMN" ||
           type == "PPP" || type == "PRP" || type == "PUS" || type == "RT" ||
           type == "SAL" || type == "SMN" || type == "SER" || type == "SKN" ||
           type == "SKM" || type == "SPRM" || type == "SPT" || type == "SPTC" ||
           type == "SPTT" || type == "STON" || type == "STL" || type == "SWT" ||
           type == "SNV" || type == "TEAR" || type == "THRT" ||
           type == "THRB" || type == "TISS" || type == "TISG" ||
           type == "TLGI" || type == "TLNG" || type == "TISPL" ||
           type == "TSMI" || type == "TISU" || type == "TUB" || type == "ULC" ||
           type == "UMB" || type == "UMED" || type == "URTH" || type == "UR" ||
           type == "URC" || type == "URT" || type == "URNS" || type == "USUB" ||
           type == "VITF" || type == "VOM" || type == "BLD" || type == "BDY" ||
           type == "WAT" || type == "WICK" || type == "WND" || type == "WNDA" ||
           type == "WNDE" || type == "WNDD";
  }
};

/*!
 * \brief The Service struct is a component of the Observations message.
 */
struct Service {
  /*!
   * \brief The Role enum
   */
  enum class Role {
    OBS, /**< Observation */
    LQC, /**< Liquid QC */
    EQC, /**< Electronic QC */
    CVR, /**< Calibration Verification */
    CAL, /**< Calibration */
    PRF, /**< Proficiency */
    UNK, /**< Unknown */
  };

  /*!
   * \brief The Status enum
   */
  enum class Status {
    NRM, /**< Normal */
    OVR, /**< Override */
    UNK, /**< Unknown */
    INI  /**< IHE extension: Initiate POC testing */
  };

  /*!
   * \brief The Reason enum
   */
  enum class Reason {
    NEW, /**< New */
    RES, /**< Resend */
    EDT  /**< Edited */
  };

  /*!
   * \brief Default constructor
   */
  Service() {}
  /*!
   * \brief Copy constructor.
   * \param service The Service to copy
   */
  Service(const Service& service) { *this = service; }
  /*!
   * \brief Overloading assignment operator.
   * \param service The Service's values to assign.
   * \return Service
   */
  Service& operator=(const Service& service) {
    if (this == &service) {
      return *this;
    }
    this->observation_uid = service.observation_uid;
    this->role = service.role;
    this->observations = service.observations;
    this->observation_dttm = service.observation_dttm;
    this->status = service.status;
    this->reason = service.reason;
    this->sequence = service.sequence;
    this->op = service.op;
    this->reagents = service.reagents;
    this->notes = service.notes;
    // patient information
    this->patient = service.patient;
    this->order = service.order;
    this->specimen = service.specimen;
    // non-patient information
    this->control = service.control;
    return *this;
  }
  /*!
   * \brief Unique identifier of the sample on the Framework
   */
  CE observation_uid;
  /*!
   * \brief Is this a patient test, a QC test, Calibration test, etc.?
   */
  CV role;
  /*!
   * \brief The list of Observations.
   */
  std::list<Observation> observations;
  /*!
   * \brief The time the observation (test) was performed.
   */
  time_t observation_dttm;
  /*!
   * \brief Was this test performed normally or under 'override' conditions.
   */
  std::optional<CV> status;
  /*!
   * \brief Are these observations 'original', re-sent, edited?
   */
  std::optional<CV> reason;
  /*!
   * \brief An std::optional number to indicate the position of this service in
   * a historical list of services performed by this Device. This number is
   * unique only accross a single Device, and may wrap
   */
  std::optional<int> sequence;
  /*!
   * \brief The operator.
   */
  std::optional<Operator> op;
  /*!
   * \brief The list of Reagents.
   */
  std::list<Reagent> reagents;
  /*!
   * \brief The list of Notes.
   */
  std::list<Note> notes;

  ///////////////////////
  /// Patient related ///
  ///////////////////////
  /*!
   * \brief The Patient.
   */
  std::optional<Patient> patient;
  /*!
   * \brief The order.
   */
  std::optional<Order> order;
  /*!
   * \brief The Specimen.
   */
  std::optional<Specimen> specimen;

  ///////////////////////////
  /// Non-Patient related ///
  ///////////////////////////
  /*!
   * \brief The QC/Calibration object
   */
  std::optional<ControlCalibration> control;

  static bool IsValidRole(const std::string& role) {
    return role == "UNK" || role == "OBS" || role == "LQC" || role == "EQC" ||
           role == "CVR" || role == "CAL" || role == "PRF";
  }

  static bool IsValidStatus(const std::string& status) {
    return status == "NRM" || status == "OVR" || status == "UNK";
  }

  static bool IsValidReason(const std::string& reason) {
    return reason == "NEW" || reason == "RES" || reason == "EDT";
  }
};

/*!
 * \brief The Terminate struct is a component of the Terminate message.
 */
struct Terminate {
  /*!
   * \brief The Reason enum
   */
  enum class Reason {
    NRM, /**< Normal */
    ABN, /**< Abnormal */
    USR, /**< User */
    UNK  /**< Unknown */
  };

  /*!
   * \brief Default constructor.
   */
  Terminate() = default;
  /*!
   * \brief Copy constructor.
   * \param terminate The Terminate to copy.
   */
  Terminate(const Terminate& terminate) { *this = terminate; }
  /*!
   * \brief Overloading assignment operator.
   * \param terminate The Terminate's values to assign.
   * \return Terminate.
   */
  Terminate& operator=(const Terminate& terminate) {
    if (this == &terminate) {
      return *this;
    }
    this->reason = terminate.reason;
    this->note = terminate.note;
    return *this;
  }

  /*!
   * \brief The reason for terminating the conversation.
   */
  CV reason;
  /*!
   * \brief An std::optional text message that may be logged or
   * displayed.
   */
  std::optional<std::string> note;

  /*!
   * \brief Check if the given reason is a valid Reason Type.
   * \param trm_code The Reason type to check.
   * \return true if it is a reason value; false otherwise.
   */
  static bool IsValidReason(const std::string& trm_reason) {
    return trm_reason == "NRM" || trm_reason == "ABN" || trm_reason == "USR" ||
           trm_reason == "UNK";
  }
};

/*!
 * \brief The MsgStatus enum
 */
enum class MsgStatus {
  PENDING,      /**< Message pending, waiting to be delivered. */
  DELIVERED,    /**< Message successfully delivered. */
  UNDELIVERABLE /** Message undelivered, an error occurred. */
};

}  // namespace accm
