#ifndef APG_PERSEK_PROTOCOL__PROTOCOL_H
#define APG_PERSEK_PROTOCOL__PROTOCOL_H

// system includes
#include <vector>
#include <map>

// includes
#include "basic_parser/object.h"
#include "generic_protocol/protocol.h"

// includes for used modules
#include "basic_objects/protocol.h"
#include "dtmf_tools_protocol/protocol.h"
#include "lang_tools_protocol/protocol.h"

namespace persek_protocol
{

// Enum
enum class voice_e
{
    UNDEF                = 0,
    MALE_A               = 1,
    FEMALE_A             = 2,
};

// Enum
enum class urgency_e
{
    UNDEF                = 0,
    IMMEDIATE            = 1,
    TIMED                = 2,
};

// Enum
enum class JobInfo_type_e
{
    UNDEF                = 0,
    SAY                  = 1,
    SAY_FEEDBACK         = 2,
    FSM                  = 3,
    REMINDER             = 4,
};

// Enum
enum class exit_status_e
{
    DONE                 = 0,
    CANCELLED,
    FAILED,
    REFUSED_BY_RECIPIENT,
    ABORTED_BY_RECIPIENT,
};

// Enum
enum class OpenJobStatus_state_e
{
    IDLE                 = 1,
    WAITING_PROC_STARTED = 2,
    ACTIVE               = 3,
    WRONG_ACTIVE         = 4,
    CANCELLED_IN_A       = 5,
    CANCELLED_IN_WPS     = 6,
    COMPLETED            = 7,
    WAITING_REDIAL_TIMER = 8,
};

// Enum
enum class FindJobRequest_status_e
{
    ANY                  = 0,
    OPEN                 = 1,
    CLOSED               = 2,
};

// Enum
enum class action_type_e
{
    NONE                 = 0,
    REPEAT               = 1,
    DROP                 = 2,
};

// Enum
enum class ContactPhone_type_e
{
    DFLT                 = 0,
    LANDLINE             = 1,
    MOBILE               = 2,
};

// Enum
enum class gender_e
{
    UNDEF                = 0,
    MALE                 = 1,
    FEMALE               = 2,
};

// Enum
enum class ReminderAction_type_e
{
    NONE                 = 0,
    REPEAT               = 1,
    DROP_FEEDBACK        = 2,
    DROP_SNOOZE          = 3,
};

// Object
struct JobOptions
{
    voice_e              voice     ;
    urgency_e            urgency   ;
    lang_tools_protocol::lang_e lang      ;
    uint32_t             exec_time ;
    uint32_t             max_tries ;
    bool                 redial_if_no_feedback;
    basic_objects::TimeWindow time_window;
    basic_objects::Weekdays weekdays_mask;
};

// Object
struct JobInfo
{
    uint32_t             job_id    ;
    uint32_t             user_id   ;
    JobInfo_type_e       type      ;
    std::string          contact   ;
    uint32_t             creation_time;
    JobOptions           options   ;
};

// Object
struct ClosedJobStatus
{
    uint32_t             job_id    ;
    exit_status_e        exit_code ;
    std::vector<uint32_t> feedback  ;
    uint32_t             num_tries ;
    uint32_t             timestamp ;
    std::string          comment   ;
};

// Object
struct OpenJobStatus
{
    uint32_t             job_id    ;
    OpenJobStatus_state_e state     ;
    uint32_t             current_try;
    uint32_t             timestamp ;
    uint32_t             next_exec_time;
};

// Object
struct TemplateInfo
{
    uint32_t             id        ;
    uint32_t             category_id;
    std::string          name      ;
    lang_tools_protocol::lang_e lang      ;
    std::string          localized_name;
    std::vector<std::string> placeholders;
};

// Object
struct CancellationFailureReason
{
    uint32_t             job_id    ;
    generic_protocol::ErrorResponse_type_e type      ;
    std::string          descr     ;
};

// Object
struct Action
{
    action_type_e        type      ;
    uint32_t             msg_templ_id;
};

// Object
struct ContactPhone
{
    ContactPhone_type_e  type      ;
    std::string          phone_number;
};

// Object
struct ContactPhoneWithId
{
    uint32_t             contact_phone_id;
    ContactPhone         contact_phone;
};

// Object
struct Contact
{
    gender_e             gender    ;
    std::string          name      ;
    std::string          first_name;
    basic_objects::Date  birthday  ;
    std::string          notice    ;
};

// Object
struct ExtendedContactInfo
{
    voice_e              voice     ;
    lang_tools_protocol::lang_e lang      ;
    uint32_t             max_tries ;
    bool                 redial_if_no_feedback;
    basic_objects::TimeWindow time_window;
    basic_objects::Weekdays weekdays  ;
};

// Object
struct ReminderAction
{
    ReminderAction_type_e type      ;
    uint32_t             msg_templ_id;
};

// Object
struct ReminderOptions
{
    voice_e              voice     ;
    lang_tools_protocol::lang_e lang      ;
    uint32_t             max_tries ;
    bool                 redial_if_no_feedback;
    basic_objects::TimeWindow time_window;
    basic_objects::Weekdays weekdays  ;
};

// Object
struct Reminder
{
    uint32_t             msg_templ_id;
    uint32_t             feedback_templ_id;
    uint32_t             effective_time;
    uint32_t             remind_period;
    std::map<std::string, std::string> params    ;
    std::map<dtmf_tools_protocol::tone_e, ReminderAction> actions   ;
    ReminderOptions      options   ;
};

// Base message
struct Request: public generic_protocol::Request
{
};

// Base message
struct BackwardMessage: public generic_protocol::BackwardMessage
{
};

// Message
struct GetJobInfoRequest: public Request
{
    enum
    {
        message_id = 247838131
    };

    uint32_t             user_id   ;
    std::vector<uint32_t> job_ids   ;
};

// Message
struct GetJobInfoResponse: public BackwardMessage
{
    enum
    {
        message_id = 211170594
    };

    std::vector<JobInfo> jobs      ;
};

// Message
struct GetJobStatRequest: public Request
{
    enum
    {
        message_id = 933263465
    };

    uint32_t             user_id   ;
    std::vector<uint32_t> job_ids   ;
};

// Message
struct GetJobStatResponse: public BackwardMessage
{
    enum
    {
        message_id = 1789487909
    };

    std::vector<OpenJobStatus> open_jobs ;
    std::vector<ClosedJobStatus> closed_jobs;
};

// Message
struct FindJobRequest: public Request
{
    enum
    {
        message_id = 2871333061
    };

    uint32_t             user_id   ;
    FindJobRequest_status_e status    ;
    std::string          contact_regex;
    basic_objects::TimeRange creation_time_range;
    basic_objects::TimeRange exec_time_range;
    basic_objects::TimeRange update_time_range;
    uint32_t             max_results;
    uint32_t             offset    ;
};

// Message
struct FindJobResponse: public BackwardMessage
{
    enum
    {
        message_id = 3042247054
    };

    uint32_t             total_size;
    std::vector<uint32_t> job_ids   ;
};

// Message
struct FindTemplatesRequest: public Request
{
    enum
    {
        message_id = 1529258977
    };

    uint32_t             user_id   ;
    uint32_t             category_id;
    std::string          name_regex;
    lang_tools_protocol::lang_e lang      ;
};

// Message
struct FindTemplatesResponse: public BackwardMessage
{
    enum
    {
        message_id = 2309416684
    };

    std::vector<TemplateInfo> templates ;
};

// Message
struct CancelJobRequest: public Request
{
    enum
    {
        message_id = 1528875807
    };

    uint32_t             job_id    ;
};

// Message
struct CancelJobResponse: public BackwardMessage
{
    enum
    {
        message_id = 3550691231
    };
};

// Message
struct CancelJobsRequest: public Request
{
    enum
    {
        message_id = 974485077
    };

    std::vector<uint32_t> job_ids   ;
};

// Message
struct CancelJobsResponse: public BackwardMessage
{
    enum
    {
        message_id = 1170973356
    };

    std::vector<uint32_t> cancelled_job_ids;
    std::vector<CancellationFailureReason> failed_jobs;
};

// Message
struct SayRequest: public Request
{
    enum
    {
        message_id = 1768841570
    };

    uint32_t             user_id   ;
    std::string          contact_id;
    uint32_t             msg_templ_id;
    std::map<std::string, std::string> params    ;
    JobOptions           options   ;
};

// Message
struct SayResponse: public BackwardMessage
{
    enum
    {
        message_id = 4247092404
    };

    uint32_t             job_id    ;
};

// Message
struct SayFeedbackRequest: public Request
{
    enum
    {
        message_id = 2011852133
    };

    uint32_t             user_id   ;
    std::string          contact_id;
    uint32_t             msg_templ_id;
    uint32_t             feedback_templ_id;
    std::map<std::string, std::string> params    ;
    std::map<dtmf_tools_protocol::tone_e, Action> actions   ;
    JobOptions           options   ;
};

// Message
struct SayFeedbackResponse: public BackwardMessage
{
    enum
    {
        message_id = 1667198235
    };

    uint32_t             job_id    ;
};

// Message
struct AddContactPhoneRequest: public Request
{
    enum
    {
        message_id = 2603033763
    };

    uint32_t             contact_id;
    ContactPhone         contact_phone;
};

// Message
struct AddContactPhoneResponse: public BackwardMessage
{
    enum
    {
        message_id = 297060311
    };

    uint32_t             contact_phone_id;
};

// Message
struct ModifyContactPhoneRequest: public Request
{
    enum
    {
        message_id = 2432324236
    };

    uint32_t             contact_phone_id;
    ContactPhone         contact_phone;
};

// Message
struct ModifyContactPhoneResponse: public BackwardMessage
{
    enum
    {
        message_id = 3127781368
    };
};

// Message
struct DeleteContactPhoneRequest: public Request
{
    enum
    {
        message_id = 1808257789
    };

    uint32_t             contact_phone_id;
};

// Message
struct DeleteContactPhoneResponse: public BackwardMessage
{
    enum
    {
        message_id = 2643942354
    };
};

// Message
struct GetContactPhoneRequest: public Request
{
    enum
    {
        message_id = 2529842840
    };

    uint32_t             contact_phone_id;
};

// Message
struct GetContactPhoneResponse: public BackwardMessage
{
    enum
    {
        message_id = 2696070017
    };

    uint32_t             contact_id;
    ContactPhone         contact_phone;
};

// Message
struct AddContactRequest: public Request
{
    enum
    {
        message_id = 2434042624
    };

    uint32_t             user_id   ;
    Contact              contact   ;
};

// Message
struct AddContactResponse: public BackwardMessage
{
    enum
    {
        message_id = 1583416874
    };

    uint32_t             contact_id;
};

// Message
struct ModifyContactRequest: public Request
{
    enum
    {
        message_id = 2648084898
    };

    uint32_t             contact_id;
    Contact              contact   ;
};

// Message
struct ModifyContactResponse: public BackwardMessage
{
    enum
    {
        message_id = 1723139828
    };
};

// Message
struct DeleteContactRequest: public Request
{
    enum
    {
        message_id = 4196830249
    };

    uint32_t             contact_id;
};

// Message
struct DeleteContactResponse: public BackwardMessage
{
    enum
    {
        message_id = 481864769
    };
};

// Message
struct GetContactRequest: public Request
{
    enum
    {
        message_id = 3693753046
    };

    uint32_t             contact_id;
};

// Message
struct GetContactResponse: public BackwardMessage
{
    enum
    {
        message_id = 832327538
    };

    Contact              contact   ;
    std::vector<uint32_t> contact_phone_ids;
};

// Message
struct GetContactWithPhonesRequest: public Request
{
    enum
    {
        message_id = 2090663452
    };

    uint32_t             contact_id;
};

// Message
struct GetContactWithPhonesResponse: public BackwardMessage
{
    enum
    {
        message_id = 1250808336
    };

    Contact              contact   ;
    std::vector<ContactPhoneWithId> contact_phones;
};

// Message
struct GetContactExtRequest: public Request
{
    enum
    {
        message_id = 1167301108
    };

    uint32_t             contact_id;
};

// Message
struct GetContactExtResponse: public BackwardMessage
{
    enum
    {
        message_id = 3831871293
    };

    Contact              contact   ;
    std::vector<ContactPhoneWithId> contact_phones;
    ExtendedContactInfo  extended_info;
};

// Message
struct GetExtendedContactInfoRequest: public Request
{
    enum
    {
        message_id = 3440168544
    };

    uint32_t             contact_id;
};

// Message
struct GetExtendedContactInfoResponse: public BackwardMessage
{
    enum
    {
        message_id = 328171319
    };

    ExtendedContactInfo  extended_info;
};

// Message
struct SetExtendedContactInfoRequest: public Request
{
    enum
    {
        message_id = 480911796
    };

    uint32_t             contact_id;
    ExtendedContactInfo  extended_info;
};

// Message
struct SetExtendedContactInfoResponse: public BackwardMessage
{
    enum
    {
        message_id = 2464206613
    };
};

// Message
struct AddReminderRequest: public Request
{
    enum
    {
        message_id = 2972837907
    };

    uint32_t             contact_phone_id;
    Reminder             reminder  ;
};

// Message
struct AddReminderResponse: public BackwardMessage
{
    enum
    {
        message_id = 3674170007
    };

    uint32_t             job_id    ;
};

// Message
struct ModifyReminderRequest: public Request
{
    enum
    {
        message_id = 2313545933
    };

    uint32_t             job_id    ;
    uint32_t             contact_phone_id;
    Reminder             reminder  ;
};

// Message
struct ModifyReminderResponse: public BackwardMessage
{
    enum
    {
        message_id = 3148630340
    };
};

// Message
struct GetReminderRequest: public Request
{
    enum
    {
        message_id = 3737952587
    };

    uint32_t             job_id    ;
};

// Message
struct GetReminderResponse: public BackwardMessage
{
    enum
    {
        message_id = 3206563352
    };

    uint32_t             contact_id;
    uint32_t             contact_phone_id;
    std::string          contact_phone;
    Reminder             reminder  ;
};

// Message
struct GetReminderStatusRequest: public Request
{
    enum
    {
        message_id = 4096306297
    };

    uint32_t             user_id   ;
    std::string          search_filter;
    basic_objects::TimeRange effective_date_time_range;
    uint32_t             page_size ;
    uint32_t             page_number;
};

} // namespace persek_protocol

#endif // APG_PERSEK_PROTOCOL__PROTOCOL_H

