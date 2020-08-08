#ifndef APG_PERSEK__OBJECT_INITIALIZER_H
#define APG_PERSEK__OBJECT_INITIALIZER_H

// includes
#include "protocol.h"

namespace persek_protocol
{

// objects

void initialize( JobOptions * res
    , voice_e voice
    , urgency_e urgency
    , lang_tools::lang_e lang
    , uint32_t exec_time
    , uint32_t max_tries
    , bool redial_if_no_feedback
    , const basic_objects::TimeWindow &  time_window
    , const basic_objects::Weekdays &  weekdays_mask
 );
void initialize( JobInfo * res
    , uint32_t job_id
    , uint32_t user_id
    , JobInfo_type_e type
    , const std::string &  contact
    , uint32_t creation_time
    , const JobOptions &  options
 );
void initialize( ClosedJobStatus * res
    , uint32_t job_id
    , exit_status_e exit_code
    , const std::vector<uint32_t> &  feedback
    , uint32_t num_tries
    , uint32_t timestamp
    , const std::string &  comment
 );
void initialize( OpenJobStatus * res
    , uint32_t job_id
    , OpenJobStatus_state_e state
    , uint32_t current_try
    , uint32_t timestamp
    , uint32_t next_exec_time
 );
void initialize( TemplateInfo * res
    , uint32_t id
    , uint32_t category_id
    , const std::string &  name
    , lang_tools::lang_e lang
    , const std::string &  localized_name
    , const std::vector<std::string> &  placeholders
 );
void initialize( CancellationFailureReason * res
    , uint32_t job_id
    , generic_protocol::ErrorResponse_type_e type
    , const std::string &  descr
 );
void initialize( Action * res
    , action_type_e type
    , uint32_t msg_templ_id
 );
void initialize( ContactPhone * res
    , ContactPhone_type_e type
    , const std::string &  phone_number
 );
void initialize( ContactPhoneWithId * res
    , uint32_t contact_phone_id
    , const ContactPhone &  contact_phone
 );
void initialize( Contact * res
    , gender_e gender
    , const std::string &  name
    , const std::string &  first_name
    , const basic_objects::Date &  birthday
    , const std::string &  notice
 );
void initialize( ExtendedContactInfo * res
    , voice_e voice
    , lang_tools::lang_e lang
    , uint32_t max_tries
    , bool redial_if_no_feedback
    , const basic_objects::TimeWindow &  time_window
    , const basic_objects::Weekdays &  weekdays
 );
void initialize( ReminderAction * res
    , ReminderAction_type_e type
    , uint32_t msg_templ_id
 );
void initialize( ReminderOptions * res
    , voice_e voice
    , lang_tools::lang_e lang
    , uint32_t max_tries
    , bool redial_if_no_feedback
    , const basic_objects::TimeWindow &  time_window
    , const basic_objects::Weekdays &  weekdays
 );
void initialize( Reminder * res
    , uint32_t msg_templ_id
    , uint32_t feedback_templ_id
    , uint32_t effective_time
    , uint32_t remind_period
    , const std::map<std::string, std::string> &  params
    , const std::map<dtmf_tools::tone_e, ReminderAction> &  actions
    , const ReminderOptions &  options
 );

// base messages

void initialize( Request * res
    , const std::string &  base_class_param_1
 );
void initialize( BackwardMessage * res
 );

// messages

void initialize( GetJobInfoRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::vector<uint32_t> &  job_ids
 );
void initialize( GetJobInfoResponse * res
    , const std::vector<JobInfo> &  jobs
 );
void initialize( GetJobStatRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::vector<uint32_t> &  job_ids
 );
void initialize( GetJobStatResponse * res
    , const std::vector<OpenJobStatus> &  open_jobs
    , const std::vector<ClosedJobStatus> &  closed_jobs
 );
void initialize( FindJobRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , FindJobRequest_status_e status
    , const std::string &  contact_regex
    , const basic_objects::TimeRange &  creation_time_range
    , const basic_objects::TimeRange &  exec_time_range
    , const basic_objects::TimeRange &  update_time_range
    , uint32_t max_results
    , uint32_t offset
 );
void initialize( FindJobResponse * res
    , uint32_t total_size
    , const std::vector<uint32_t> &  job_ids
 );
void initialize( FindTemplatesRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , uint32_t category_id
    , const std::string &  name_regex
    , lang_tools::lang_e lang
 );
void initialize( FindTemplatesResponse * res
    , const std::vector<TemplateInfo> &  templates
 );
void initialize( CancelJobRequest * res
    , const std::string &  base_class_param_1
    , uint32_t job_id
 );
void initialize( CancelJobResponse * res
 );
void initialize( CancelJobsRequest * res
    , const std::string &  base_class_param_1
    , const std::vector<uint32_t> &  job_ids
 );
void initialize( CancelJobsResponse * res
    , const std::vector<uint32_t> &  cancelled_job_ids
    , const std::vector<CancellationFailureReason> &  failed_jobs
 );
void initialize( SayRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::string &  contact_id
    , uint32_t msg_templ_id
    , const std::map<std::string, std::string> &  params
    , const JobOptions &  options
 );
void initialize( SayResponse * res
    , uint32_t job_id
 );
void initialize( SayFeedbackRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::string &  contact_id
    , uint32_t msg_templ_id
    , uint32_t feedback_templ_id
    , const std::map<std::string, std::string> &  params
    , const std::map<dtmf_tools::tone_e, Action> &  actions
    , const JobOptions &  options
 );
void initialize( SayFeedbackResponse * res
    , uint32_t job_id
 );
void initialize( AddContactPhoneRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
    , const ContactPhone &  contact_phone
 );
void initialize( AddContactPhoneResponse * res
    , uint32_t contact_phone_id
 );
void initialize( ModifyContactPhoneRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_phone_id
    , const ContactPhone &  contact_phone
 );
void initialize( ModifyContactPhoneResponse * res
 );
void initialize( DeleteContactPhoneRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_phone_id
 );
void initialize( DeleteContactPhoneResponse * res
 );
void initialize( GetContactPhoneRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_phone_id
 );
void initialize( GetContactPhoneResponse * res
    , uint32_t contact_id
    , const ContactPhone &  contact_phone
 );
void initialize( AddContactRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const Contact &  contact
 );
void initialize( AddContactResponse * res
    , uint32_t contact_id
 );
void initialize( ModifyContactRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
    , const Contact &  contact
 );
void initialize( ModifyContactResponse * res
 );
void initialize( DeleteContactRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
 );
void initialize( DeleteContactResponse * res
 );
void initialize( GetContactRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
 );
void initialize( GetContactResponse * res
    , const Contact &  contact
    , const std::vector<uint32_t> &  contact_phone_ids
 );
void initialize( GetContactWithPhonesRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
 );
void initialize( GetContactWithPhonesResponse * res
    , const Contact &  contact
    , const std::vector<ContactPhoneWithId> &  contact_phones
 );
void initialize( GetContactExtRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
 );
void initialize( GetContactExtResponse * res
    , const Contact &  contact
    , const std::vector<ContactPhoneWithId> &  contact_phones
    , const ExtendedContactInfo &  extended_info
 );
void initialize( GetExtendedContactInfoRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
 );
void initialize( GetExtendedContactInfoResponse * res
    , const ExtendedContactInfo &  extended_info
 );
void initialize( SetExtendedContactInfoRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
    , const ExtendedContactInfo &  extended_info
 );
void initialize( SetExtendedContactInfoResponse * res
 );
void initialize( AddReminderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_phone_id
    , const Reminder &  reminder
 );
void initialize( AddReminderResponse * res
    , uint32_t job_id
 );
void initialize( ModifyReminderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t job_id
    , uint32_t contact_phone_id
    , const Reminder &  reminder
 );
void initialize( ModifyReminderResponse * res
 );
void initialize( GetReminderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t job_id
 );
void initialize( GetReminderResponse * res
    , uint32_t contact_id
    , uint32_t contact_phone_id
    , const std::string &  contact_phone
    , const Reminder &  reminder
 );
void initialize( GetReminderStatusRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::string &  search_filter
    , const basic_objects::TimeRange &  effective_date_time_range
    , uint32_t page_size
    , uint32_t page_number
 );

// messages (constructors)

GetJobInfoRequest * create_GetJobInfoRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::vector<uint32_t> &  job_ids
 );
GetJobInfoResponse * create_GetJobInfoResponse(
    const std::vector<JobInfo> &  jobs
 );
GetJobStatRequest * create_GetJobStatRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::vector<uint32_t> &  job_ids
 );
GetJobStatResponse * create_GetJobStatResponse(
    const std::vector<OpenJobStatus> &  open_jobs
    , const std::vector<ClosedJobStatus> &  closed_jobs
 );
FindJobRequest * create_FindJobRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , FindJobRequest_status_e status
    , const std::string &  contact_regex
    , const basic_objects::TimeRange &  creation_time_range
    , const basic_objects::TimeRange &  exec_time_range
    , const basic_objects::TimeRange &  update_time_range
    , uint32_t max_results
    , uint32_t offset
 );
FindJobResponse * create_FindJobResponse(
    uint32_t total_size
    , const std::vector<uint32_t> &  job_ids
 );
FindTemplatesRequest * create_FindTemplatesRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , uint32_t category_id
    , const std::string &  name_regex
    , lang_tools::lang_e lang
 );
FindTemplatesResponse * create_FindTemplatesResponse(
    const std::vector<TemplateInfo> &  templates
 );
CancelJobRequest * create_CancelJobRequest(
    const std::string &  base_class_param_1
    , uint32_t job_id
 );
CancelJobResponse * create_CancelJobResponse(
 );
CancelJobsRequest * create_CancelJobsRequest(
    const std::string &  base_class_param_1
    , const std::vector<uint32_t> &  job_ids
 );
CancelJobsResponse * create_CancelJobsResponse(
    const std::vector<uint32_t> &  cancelled_job_ids
    , const std::vector<CancellationFailureReason> &  failed_jobs
 );
SayRequest * create_SayRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::string &  contact_id
    , uint32_t msg_templ_id
    , const std::map<std::string, std::string> &  params
    , const JobOptions &  options
 );
SayResponse * create_SayResponse(
    uint32_t job_id
 );
SayFeedbackRequest * create_SayFeedbackRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::string &  contact_id
    , uint32_t msg_templ_id
    , uint32_t feedback_templ_id
    , const std::map<std::string, std::string> &  params
    , const std::map<dtmf_tools::tone_e, Action> &  actions
    , const JobOptions &  options
 );
SayFeedbackResponse * create_SayFeedbackResponse(
    uint32_t job_id
 );
AddContactPhoneRequest * create_AddContactPhoneRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
    , const ContactPhone &  contact_phone
 );
AddContactPhoneResponse * create_AddContactPhoneResponse(
    uint32_t contact_phone_id
 );
ModifyContactPhoneRequest * create_ModifyContactPhoneRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_phone_id
    , const ContactPhone &  contact_phone
 );
ModifyContactPhoneResponse * create_ModifyContactPhoneResponse(
 );
DeleteContactPhoneRequest * create_DeleteContactPhoneRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_phone_id
 );
DeleteContactPhoneResponse * create_DeleteContactPhoneResponse(
 );
GetContactPhoneRequest * create_GetContactPhoneRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_phone_id
 );
GetContactPhoneResponse * create_GetContactPhoneResponse(
    uint32_t contact_id
    , const ContactPhone &  contact_phone
 );
AddContactRequest * create_AddContactRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const Contact &  contact
 );
AddContactResponse * create_AddContactResponse(
    uint32_t contact_id
 );
ModifyContactRequest * create_ModifyContactRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
    , const Contact &  contact
 );
ModifyContactResponse * create_ModifyContactResponse(
 );
DeleteContactRequest * create_DeleteContactRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
 );
DeleteContactResponse * create_DeleteContactResponse(
 );
GetContactRequest * create_GetContactRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
 );
GetContactResponse * create_GetContactResponse(
    const Contact &  contact
    , const std::vector<uint32_t> &  contact_phone_ids
 );
GetContactWithPhonesRequest * create_GetContactWithPhonesRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
 );
GetContactWithPhonesResponse * create_GetContactWithPhonesResponse(
    const Contact &  contact
    , const std::vector<ContactPhoneWithId> &  contact_phones
 );
GetContactExtRequest * create_GetContactExtRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
 );
GetContactExtResponse * create_GetContactExtResponse(
    const Contact &  contact
    , const std::vector<ContactPhoneWithId> &  contact_phones
    , const ExtendedContactInfo &  extended_info
 );
GetExtendedContactInfoRequest * create_GetExtendedContactInfoRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
 );
GetExtendedContactInfoResponse * create_GetExtendedContactInfoResponse(
    const ExtendedContactInfo &  extended_info
 );
SetExtendedContactInfoRequest * create_SetExtendedContactInfoRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
    , const ExtendedContactInfo &  extended_info
 );
SetExtendedContactInfoResponse * create_SetExtendedContactInfoResponse(
 );
AddReminderRequest * create_AddReminderRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_phone_id
    , const Reminder &  reminder
 );
AddReminderResponse * create_AddReminderResponse(
    uint32_t job_id
 );
ModifyReminderRequest * create_ModifyReminderRequest(
    const std::string &  base_class_param_1
    , uint32_t job_id
    , uint32_t contact_phone_id
    , const Reminder &  reminder
 );
ModifyReminderResponse * create_ModifyReminderResponse(
 );
GetReminderRequest * create_GetReminderRequest(
    const std::string &  base_class_param_1
    , uint32_t job_id
 );
GetReminderResponse * create_GetReminderResponse(
    uint32_t contact_id
    , uint32_t contact_phone_id
    , const std::string &  contact_phone
    , const Reminder &  reminder
 );
GetReminderStatusRequest * create_GetReminderStatusRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::string &  search_filter
    , const basic_objects::TimeRange &  effective_date_time_range
    , uint32_t page_size
    , uint32_t page_number
 );

} // namespace persek_protocol

#endif // APG_PERSEK__OBJECT_INITIALIZER_H
