// includes
#include "object_initializer.h"
#include "generic_protocol/object_initializer.h"
#include "basic_objects/object_initializer.h"
#include "dtmf_tools/object_initializer.h"
#include "lang_tools/object_initializer.h"

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
 )
{
    res->voice = voice;
    res->urgency = urgency;
    res->lang = lang;
    res->exec_time = exec_time;
    res->max_tries = max_tries;
    res->redial_if_no_feedback = redial_if_no_feedback;
    res->time_window = time_window;
    res->weekdays_mask = weekdays_mask;
}

void initialize( JobInfo * res
    , uint32_t job_id
    , uint32_t user_id
    , JobInfo_type_e type
    , const std::string &  contact
    , uint32_t creation_time
    , const JobOptions &  options
 )
{
    res->job_id = job_id;
    res->user_id = user_id;
    res->type = type;
    res->contact = contact;
    res->creation_time = creation_time;
    res->options = options;
}

void initialize( ClosedJobStatus * res
    , uint32_t job_id
    , exit_status_e exit_code
    , const std::vector<uint32_t> &  feedback
    , uint32_t num_tries
    , uint32_t timestamp
    , const std::string &  comment
 )
{
    res->job_id = job_id;
    res->exit_code = exit_code;
    res->feedback = feedback;
    res->num_tries = num_tries;
    res->timestamp = timestamp;
    res->comment = comment;
}

void initialize( OpenJobStatus * res
    , uint32_t job_id
    , OpenJobStatus_state_e state
    , uint32_t current_try
    , uint32_t timestamp
    , uint32_t next_exec_time
 )
{
    res->job_id = job_id;
    res->state = state;
    res->current_try = current_try;
    res->timestamp = timestamp;
    res->next_exec_time = next_exec_time;
}

void initialize( TemplateInfo * res
    , uint32_t id
    , uint32_t category_id
    , const std::string &  name
    , lang_tools::lang_e lang
    , const std::string &  localized_name
    , const std::vector<std::string> &  placeholders
 )
{
    res->id = id;
    res->category_id = category_id;
    res->name = name;
    res->lang = lang;
    res->localized_name = localized_name;
    res->placeholders = placeholders;
}

void initialize( CancellationFailureReason * res
    , uint32_t job_id
    , generic_protocol::ErrorResponse_type_e type
    , const std::string &  descr
 )
{
    res->job_id = job_id;
    res->type = type;
    res->descr = descr;
}

void initialize( Action * res
    , action_type_e type
    , uint32_t msg_templ_id
 )
{
    res->type = type;
    res->msg_templ_id = msg_templ_id;
}

void initialize( ContactPhone * res
    , ContactPhone_type_e type
    , const std::string &  phone_number
 )
{
    res->type = type;
    res->phone_number = phone_number;
}

void initialize( ContactPhoneWithId * res
    , uint32_t contact_phone_id
    , const ContactPhone &  contact_phone
 )
{
    res->contact_phone_id = contact_phone_id;
    res->contact_phone = contact_phone;
}

void initialize( Contact * res
    , gender_e gender
    , const std::string &  name
    , const std::string &  first_name
    , const basic_objects::Date &  birthday
    , const std::string &  notice
 )
{
    res->gender = gender;
    res->name = name;
    res->first_name = first_name;
    res->birthday = birthday;
    res->notice = notice;
}

void initialize( ExtendedContactInfo * res
    , voice_e voice
    , lang_tools::lang_e lang
    , uint32_t max_tries
    , bool redial_if_no_feedback
    , const basic_objects::TimeWindow &  time_window
    , const basic_objects::Weekdays &  weekdays
 )
{
    res->voice = voice;
    res->lang = lang;
    res->max_tries = max_tries;
    res->redial_if_no_feedback = redial_if_no_feedback;
    res->time_window = time_window;
    res->weekdays = weekdays;
}

void initialize( ReminderAction * res
    , ReminderAction_type_e type
    , uint32_t msg_templ_id
 )
{
    res->type = type;
    res->msg_templ_id = msg_templ_id;
}

void initialize( ReminderOptions * res
    , voice_e voice
    , lang_tools::lang_e lang
    , uint32_t max_tries
    , bool redial_if_no_feedback
    , const basic_objects::TimeWindow &  time_window
    , const basic_objects::Weekdays &  weekdays
 )
{
    res->voice = voice;
    res->lang = lang;
    res->max_tries = max_tries;
    res->redial_if_no_feedback = redial_if_no_feedback;
    res->time_window = time_window;
    res->weekdays = weekdays;
}

void initialize( Reminder * res
    , uint32_t msg_templ_id
    , uint32_t feedback_templ_id
    , uint32_t effective_time
    , uint32_t remind_period
    , const std::map<std::string, std::string> &  params
    , const std::map<dtmf_tools::tone_e, ReminderAction> &  actions
    , const ReminderOptions &  options
 )
{
    res->msg_templ_id = msg_templ_id;
    res->feedback_templ_id = feedback_templ_id;
    res->effective_time = effective_time;
    res->remind_period = remind_period;
    res->params = params;
    res->actions = actions;
    res->options = options;
}

// base messages

void initialize( Request * res
    , const std::string &  base_class_param_1
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::Request*>( res ), base_class_param_1 );

}

void initialize( BackwardMessage * res
 )
{
    // no base class
}

// messages

void initialize( GetJobInfoRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::vector<uint32_t> &  job_ids
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->user_id = user_id;
    res->job_ids = job_ids;
}

void initialize( GetJobInfoResponse * res
    , const std::vector<JobInfo> &  jobs
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->jobs = jobs;
}

void initialize( GetJobStatRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::vector<uint32_t> &  job_ids
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->user_id = user_id;
    res->job_ids = job_ids;
}

void initialize( GetJobStatResponse * res
    , const std::vector<OpenJobStatus> &  open_jobs
    , const std::vector<ClosedJobStatus> &  closed_jobs
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->open_jobs = open_jobs;
    res->closed_jobs = closed_jobs;
}

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
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->user_id = user_id;
    res->status = status;
    res->contact_regex = contact_regex;
    res->creation_time_range = creation_time_range;
    res->exec_time_range = exec_time_range;
    res->update_time_range = update_time_range;
    res->max_results = max_results;
    res->offset = offset;
}

void initialize( FindJobResponse * res
    , uint32_t total_size
    , const std::vector<uint32_t> &  job_ids
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->total_size = total_size;
    res->job_ids = job_ids;
}

void initialize( FindTemplatesRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , uint32_t category_id
    , const std::string &  name_regex
    , lang_tools::lang_e lang
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->user_id = user_id;
    res->category_id = category_id;
    res->name_regex = name_regex;
    res->lang = lang;
}

void initialize( FindTemplatesResponse * res
    , const std::vector<TemplateInfo> &  templates
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->templates = templates;
}

void initialize( CancelJobRequest * res
    , const std::string &  base_class_param_1
    , uint32_t job_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->job_id = job_id;
}

void initialize( CancelJobResponse * res
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

}

void initialize( CancelJobsRequest * res
    , const std::string &  base_class_param_1
    , const std::vector<uint32_t> &  job_ids
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->job_ids = job_ids;
}

void initialize( CancelJobsResponse * res
    , const std::vector<uint32_t> &  cancelled_job_ids
    , const std::vector<CancellationFailureReason> &  failed_jobs
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->cancelled_job_ids = cancelled_job_ids;
    res->failed_jobs = failed_jobs;
}

void initialize( SayRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::string &  contact_id
    , uint32_t msg_templ_id
    , const std::map<std::string, std::string> &  params
    , const JobOptions &  options
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->user_id = user_id;
    res->contact_id = contact_id;
    res->msg_templ_id = msg_templ_id;
    res->params = params;
    res->options = options;
}

void initialize( SayResponse * res
    , uint32_t job_id
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->job_id = job_id;
}

void initialize( SayFeedbackRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::string &  contact_id
    , uint32_t msg_templ_id
    , uint32_t feedback_templ_id
    , const std::map<std::string, std::string> &  params
    , const std::map<dtmf_tools::tone_e, Action> &  actions
    , const JobOptions &  options
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->user_id = user_id;
    res->contact_id = contact_id;
    res->msg_templ_id = msg_templ_id;
    res->feedback_templ_id = feedback_templ_id;
    res->params = params;
    res->actions = actions;
    res->options = options;
}

void initialize( SayFeedbackResponse * res
    , uint32_t job_id
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->job_id = job_id;
}

void initialize( AddContactPhoneRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
    , const ContactPhone &  contact_phone
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->contact_id = contact_id;
    res->contact_phone = contact_phone;
}

void initialize( AddContactPhoneResponse * res
    , uint32_t contact_phone_id
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->contact_phone_id = contact_phone_id;
}

void initialize( ModifyContactPhoneRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_phone_id
    , const ContactPhone &  contact_phone
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->contact_phone_id = contact_phone_id;
    res->contact_phone = contact_phone;
}

void initialize( ModifyContactPhoneResponse * res
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

}

void initialize( DeleteContactPhoneRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_phone_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->contact_phone_id = contact_phone_id;
}

void initialize( DeleteContactPhoneResponse * res
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

}

void initialize( GetContactPhoneRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_phone_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->contact_phone_id = contact_phone_id;
}

void initialize( GetContactPhoneResponse * res
    , uint32_t contact_id
    , const ContactPhone &  contact_phone
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->contact_id = contact_id;
    res->contact_phone = contact_phone;
}

void initialize( AddContactRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const Contact &  contact
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->user_id = user_id;
    res->contact = contact;
}

void initialize( AddContactResponse * res
    , uint32_t contact_id
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->contact_id = contact_id;
}

void initialize( ModifyContactRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
    , const Contact &  contact
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->contact_id = contact_id;
    res->contact = contact;
}

void initialize( ModifyContactResponse * res
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

}

void initialize( DeleteContactRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->contact_id = contact_id;
}

void initialize( DeleteContactResponse * res
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

}

void initialize( GetContactRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->contact_id = contact_id;
}

void initialize( GetContactResponse * res
    , const Contact &  contact
    , const std::vector<uint32_t> &  contact_phone_ids
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->contact = contact;
    res->contact_phone_ids = contact_phone_ids;
}

void initialize( GetContactWithPhonesRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->contact_id = contact_id;
}

void initialize( GetContactWithPhonesResponse * res
    , const Contact &  contact
    , const std::vector<ContactPhoneWithId> &  contact_phones
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->contact = contact;
    res->contact_phones = contact_phones;
}

void initialize( GetContactExtRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->contact_id = contact_id;
}

void initialize( GetContactExtResponse * res
    , const Contact &  contact
    , const std::vector<ContactPhoneWithId> &  contact_phones
    , const ExtendedContactInfo &  extended_info
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->contact = contact;
    res->contact_phones = contact_phones;
    res->extended_info = extended_info;
}

void initialize( GetExtendedContactInfoRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->contact_id = contact_id;
}

void initialize( GetExtendedContactInfoResponse * res
    , const ExtendedContactInfo &  extended_info
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->extended_info = extended_info;
}

void initialize( SetExtendedContactInfoRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_id
    , const ExtendedContactInfo &  extended_info
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->contact_id = contact_id;
    res->extended_info = extended_info;
}

void initialize( SetExtendedContactInfoResponse * res
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

}

void initialize( AddReminderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t contact_phone_id
    , const Reminder &  reminder
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->contact_phone_id = contact_phone_id;
    res->reminder = reminder;
}

void initialize( AddReminderResponse * res
    , uint32_t job_id
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->job_id = job_id;
}

void initialize( ModifyReminderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t job_id
    , uint32_t contact_phone_id
    , const Reminder &  reminder
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->job_id = job_id;
    res->contact_phone_id = contact_phone_id;
    res->reminder = reminder;
}

void initialize( ModifyReminderResponse * res
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

}

void initialize( GetReminderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t job_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->job_id = job_id;
}

void initialize( GetReminderResponse * res
    , uint32_t contact_id
    , uint32_t contact_phone_id
    , const std::string &  contact_phone
    , const Reminder &  reminder
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->contact_id = contact_id;
    res->contact_phone_id = contact_phone_id;
    res->contact_phone = contact_phone;
    res->reminder = reminder;
}

void initialize( GetReminderStatusRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::string &  search_filter
    , const basic_objects::TimeRange &  effective_date_time_range
    , uint32_t page_size
    , uint32_t page_number
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->user_id = user_id;
    res->search_filter = search_filter;
    res->effective_date_time_range = effective_date_time_range;
    res->page_size = page_size;
    res->page_number = page_number;
}

// messages (constructors)

GetJobInfoRequest * create_GetJobInfoRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::vector<uint32_t> &  job_ids
 )
{
    auto * res = new GetJobInfoRequest;

    initialize( res, base_class_param_1, user_id, job_ids );

    return res;
}

GetJobInfoResponse * create_GetJobInfoResponse(
    const std::vector<JobInfo> &  jobs
 )
{
    auto * res = new GetJobInfoResponse;

    initialize( res, jobs );

    return res;
}

GetJobStatRequest * create_GetJobStatRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::vector<uint32_t> &  job_ids
 )
{
    auto * res = new GetJobStatRequest;

    initialize( res, base_class_param_1, user_id, job_ids );

    return res;
}

GetJobStatResponse * create_GetJobStatResponse(
    const std::vector<OpenJobStatus> &  open_jobs
    , const std::vector<ClosedJobStatus> &  closed_jobs
 )
{
    auto * res = new GetJobStatResponse;

    initialize( res, open_jobs, closed_jobs );

    return res;
}

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
 )
{
    auto * res = new FindJobRequest;

    initialize( res, base_class_param_1, user_id, status, contact_regex, creation_time_range, exec_time_range, update_time_range, max_results, offset );

    return res;
}

FindJobResponse * create_FindJobResponse(
    uint32_t total_size
    , const std::vector<uint32_t> &  job_ids
 )
{
    auto * res = new FindJobResponse;

    initialize( res, total_size, job_ids );

    return res;
}

FindTemplatesRequest * create_FindTemplatesRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , uint32_t category_id
    , const std::string &  name_regex
    , lang_tools::lang_e lang
 )
{
    auto * res = new FindTemplatesRequest;

    initialize( res, base_class_param_1, user_id, category_id, name_regex, lang );

    return res;
}

FindTemplatesResponse * create_FindTemplatesResponse(
    const std::vector<TemplateInfo> &  templates
 )
{
    auto * res = new FindTemplatesResponse;

    initialize( res, templates );

    return res;
}

CancelJobRequest * create_CancelJobRequest(
    const std::string &  base_class_param_1
    , uint32_t job_id
 )
{
    auto * res = new CancelJobRequest;

    initialize( res, base_class_param_1, job_id );

    return res;
}

CancelJobResponse * create_CancelJobResponse(
 )
{
    auto * res = new CancelJobResponse;

    initialize( res );

    return res;
}

CancelJobsRequest * create_CancelJobsRequest(
    const std::string &  base_class_param_1
    , const std::vector<uint32_t> &  job_ids
 )
{
    auto * res = new CancelJobsRequest;

    initialize( res, base_class_param_1, job_ids );

    return res;
}

CancelJobsResponse * create_CancelJobsResponse(
    const std::vector<uint32_t> &  cancelled_job_ids
    , const std::vector<CancellationFailureReason> &  failed_jobs
 )
{
    auto * res = new CancelJobsResponse;

    initialize( res, cancelled_job_ids, failed_jobs );

    return res;
}

SayRequest * create_SayRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::string &  contact_id
    , uint32_t msg_templ_id
    , const std::map<std::string, std::string> &  params
    , const JobOptions &  options
 )
{
    auto * res = new SayRequest;

    initialize( res, base_class_param_1, user_id, contact_id, msg_templ_id, params, options );

    return res;
}

SayResponse * create_SayResponse(
    uint32_t job_id
 )
{
    auto * res = new SayResponse;

    initialize( res, job_id );

    return res;
}

SayFeedbackRequest * create_SayFeedbackRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::string &  contact_id
    , uint32_t msg_templ_id
    , uint32_t feedback_templ_id
    , const std::map<std::string, std::string> &  params
    , const std::map<dtmf_tools::tone_e, Action> &  actions
    , const JobOptions &  options
 )
{
    auto * res = new SayFeedbackRequest;

    initialize( res, base_class_param_1, user_id, contact_id, msg_templ_id, feedback_templ_id, params, actions, options );

    return res;
}

SayFeedbackResponse * create_SayFeedbackResponse(
    uint32_t job_id
 )
{
    auto * res = new SayFeedbackResponse;

    initialize( res, job_id );

    return res;
}

AddContactPhoneRequest * create_AddContactPhoneRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
    , const ContactPhone &  contact_phone
 )
{
    auto * res = new AddContactPhoneRequest;

    initialize( res, base_class_param_1, contact_id, contact_phone );

    return res;
}

AddContactPhoneResponse * create_AddContactPhoneResponse(
    uint32_t contact_phone_id
 )
{
    auto * res = new AddContactPhoneResponse;

    initialize( res, contact_phone_id );

    return res;
}

ModifyContactPhoneRequest * create_ModifyContactPhoneRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_phone_id
    , const ContactPhone &  contact_phone
 )
{
    auto * res = new ModifyContactPhoneRequest;

    initialize( res, base_class_param_1, contact_phone_id, contact_phone );

    return res;
}

ModifyContactPhoneResponse * create_ModifyContactPhoneResponse(
 )
{
    auto * res = new ModifyContactPhoneResponse;

    initialize( res );

    return res;
}

DeleteContactPhoneRequest * create_DeleteContactPhoneRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_phone_id
 )
{
    auto * res = new DeleteContactPhoneRequest;

    initialize( res, base_class_param_1, contact_phone_id );

    return res;
}

DeleteContactPhoneResponse * create_DeleteContactPhoneResponse(
 )
{
    auto * res = new DeleteContactPhoneResponse;

    initialize( res );

    return res;
}

GetContactPhoneRequest * create_GetContactPhoneRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_phone_id
 )
{
    auto * res = new GetContactPhoneRequest;

    initialize( res, base_class_param_1, contact_phone_id );

    return res;
}

GetContactPhoneResponse * create_GetContactPhoneResponse(
    uint32_t contact_id
    , const ContactPhone &  contact_phone
 )
{
    auto * res = new GetContactPhoneResponse;

    initialize( res, contact_id, contact_phone );

    return res;
}

AddContactRequest * create_AddContactRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const Contact &  contact
 )
{
    auto * res = new AddContactRequest;

    initialize( res, base_class_param_1, user_id, contact );

    return res;
}

AddContactResponse * create_AddContactResponse(
    uint32_t contact_id
 )
{
    auto * res = new AddContactResponse;

    initialize( res, contact_id );

    return res;
}

ModifyContactRequest * create_ModifyContactRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
    , const Contact &  contact
 )
{
    auto * res = new ModifyContactRequest;

    initialize( res, base_class_param_1, contact_id, contact );

    return res;
}

ModifyContactResponse * create_ModifyContactResponse(
 )
{
    auto * res = new ModifyContactResponse;

    initialize( res );

    return res;
}

DeleteContactRequest * create_DeleteContactRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
 )
{
    auto * res = new DeleteContactRequest;

    initialize( res, base_class_param_1, contact_id );

    return res;
}

DeleteContactResponse * create_DeleteContactResponse(
 )
{
    auto * res = new DeleteContactResponse;

    initialize( res );

    return res;
}

GetContactRequest * create_GetContactRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
 )
{
    auto * res = new GetContactRequest;

    initialize( res, base_class_param_1, contact_id );

    return res;
}

GetContactResponse * create_GetContactResponse(
    const Contact &  contact
    , const std::vector<uint32_t> &  contact_phone_ids
 )
{
    auto * res = new GetContactResponse;

    initialize( res, contact, contact_phone_ids );

    return res;
}

GetContactWithPhonesRequest * create_GetContactWithPhonesRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
 )
{
    auto * res = new GetContactWithPhonesRequest;

    initialize( res, base_class_param_1, contact_id );

    return res;
}

GetContactWithPhonesResponse * create_GetContactWithPhonesResponse(
    const Contact &  contact
    , const std::vector<ContactPhoneWithId> &  contact_phones
 )
{
    auto * res = new GetContactWithPhonesResponse;

    initialize( res, contact, contact_phones );

    return res;
}

GetContactExtRequest * create_GetContactExtRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
 )
{
    auto * res = new GetContactExtRequest;

    initialize( res, base_class_param_1, contact_id );

    return res;
}

GetContactExtResponse * create_GetContactExtResponse(
    const Contact &  contact
    , const std::vector<ContactPhoneWithId> &  contact_phones
    , const ExtendedContactInfo &  extended_info
 )
{
    auto * res = new GetContactExtResponse;

    initialize( res, contact, contact_phones, extended_info );

    return res;
}

GetExtendedContactInfoRequest * create_GetExtendedContactInfoRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
 )
{
    auto * res = new GetExtendedContactInfoRequest;

    initialize( res, base_class_param_1, contact_id );

    return res;
}

GetExtendedContactInfoResponse * create_GetExtendedContactInfoResponse(
    const ExtendedContactInfo &  extended_info
 )
{
    auto * res = new GetExtendedContactInfoResponse;

    initialize( res, extended_info );

    return res;
}

SetExtendedContactInfoRequest * create_SetExtendedContactInfoRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_id
    , const ExtendedContactInfo &  extended_info
 )
{
    auto * res = new SetExtendedContactInfoRequest;

    initialize( res, base_class_param_1, contact_id, extended_info );

    return res;
}

SetExtendedContactInfoResponse * create_SetExtendedContactInfoResponse(
 )
{
    auto * res = new SetExtendedContactInfoResponse;

    initialize( res );

    return res;
}

AddReminderRequest * create_AddReminderRequest(
    const std::string &  base_class_param_1
    , uint32_t contact_phone_id
    , const Reminder &  reminder
 )
{
    auto * res = new AddReminderRequest;

    initialize( res, base_class_param_1, contact_phone_id, reminder );

    return res;
}

AddReminderResponse * create_AddReminderResponse(
    uint32_t job_id
 )
{
    auto * res = new AddReminderResponse;

    initialize( res, job_id );

    return res;
}

ModifyReminderRequest * create_ModifyReminderRequest(
    const std::string &  base_class_param_1
    , uint32_t job_id
    , uint32_t contact_phone_id
    , const Reminder &  reminder
 )
{
    auto * res = new ModifyReminderRequest;

    initialize( res, base_class_param_1, job_id, contact_phone_id, reminder );

    return res;
}

ModifyReminderResponse * create_ModifyReminderResponse(
 )
{
    auto * res = new ModifyReminderResponse;

    initialize( res );

    return res;
}

GetReminderRequest * create_GetReminderRequest(
    const std::string &  base_class_param_1
    , uint32_t job_id
 )
{
    auto * res = new GetReminderRequest;

    initialize( res, base_class_param_1, job_id );

    return res;
}

GetReminderResponse * create_GetReminderResponse(
    uint32_t contact_id
    , uint32_t contact_phone_id
    , const std::string &  contact_phone
    , const Reminder &  reminder
 )
{
    auto * res = new GetReminderResponse;

    initialize( res, contact_id, contact_phone_id, contact_phone, reminder );

    return res;
}

GetReminderStatusRequest * create_GetReminderStatusRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const std::string &  search_filter
    , const basic_objects::TimeRange &  effective_date_time_range
    , uint32_t page_size
    , uint32_t page_number
 )
{
    auto * res = new GetReminderStatusRequest;

    initialize( res, base_class_param_1, user_id, search_filter, effective_date_time_range, page_size, page_number );

    return res;
}

} // namespace persek_protocol

