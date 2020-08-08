<?php

namespace persek_protocol;


// includes
require_once 'protocol.php';
require_once __DIR__.'/../generic_protocol/object_initializer.php';

// objects

function initialize__JobOptions( & $res
    , $voice // voice_e
    , $urgency // urgency_e
    , $lang // lang_tools\lang_e
    , $exec_time // uint32_t
    , $max_tries // uint32_t
    , $redial_if_no_feedback // bool
    , $time_window // basic_objects\TimeWindow
    , $weekdays_mask // basic_objects\Weekdays
 )
{
    $res->voice = $voice;
    $res->urgency = $urgency;
    $res->lang = $lang;
    $res->exec_time = $exec_time;
    $res->max_tries = $max_tries;
    $res->redial_if_no_feedback = $redial_if_no_feedback;
    $res->time_window = $time_window;
    $res->weekdays_mask = $weekdays_mask;
}

function initialize__JobInfo( & $res
    , $job_id // uint32_t
    , $user_id // uint32_t
    , $type // JobInfo_type_e
    , $contact // string
    , $creation_time // uint32_t
    , $options // JobOptions
 )
{
    $res->job_id = $job_id;
    $res->user_id = $user_id;
    $res->type = $type;
    $res->contact = $contact;
    $res->creation_time = $creation_time;
    $res->options = $options;
}

function initialize__ClosedJobStatus( & $res
    , $job_id // uint32_t
    , $exit_code // exit_status_e
    , $feedback // array<uint32_t>
    , $num_tries // uint32_t
    , $timestamp // uint32_t
    , $comment // string
 )
{
    $res->job_id = $job_id;
    $res->exit_code = $exit_code;
    $res->feedback = $feedback;
    $res->num_tries = $num_tries;
    $res->timestamp = $timestamp;
    $res->comment = $comment;
}

function initialize__OpenJobStatus( & $res
    , $job_id // uint32_t
    , $state // OpenJobStatus_state_e
    , $current_try // uint32_t
    , $timestamp // uint32_t
    , $next_exec_time // uint32_t
 )
{
    $res->job_id = $job_id;
    $res->state = $state;
    $res->current_try = $current_try;
    $res->timestamp = $timestamp;
    $res->next_exec_time = $next_exec_time;
}

function initialize__TemplateInfo( & $res
    , $id // uint32_t
    , $category_id // uint32_t
    , $name // string
    , $lang // lang_tools\lang_e
    , $localized_name // string
    , $placeholders // array<string>
 )
{
    $res->id = $id;
    $res->category_id = $category_id;
    $res->name = $name;
    $res->lang = $lang;
    $res->localized_name = $localized_name;
    $res->placeholders = $placeholders;
}

function initialize__CancellationFailureReason( & $res
    , $job_id // uint32_t
    , $type // generic_protocol\ErrorResponse_type_e
    , $descr // string
 )
{
    $res->job_id = $job_id;
    $res->type = $type;
    $res->descr = $descr;
}

function initialize__Action( & $res
    , $type // action_type_e
    , $msg_templ_id // uint32_t
 )
{
    $res->type = $type;
    $res->msg_templ_id = $msg_templ_id;
}

function initialize__ContactPhone( & $res
    , $type // ContactPhone_type_e
    , $phone_number // string
 )
{
    $res->type = $type;
    $res->phone_number = $phone_number;
}

function initialize__ContactPhoneWithId( & $res
    , $contact_phone_id // uint32_t
    , $contact_phone // ContactPhone
 )
{
    $res->contact_phone_id = $contact_phone_id;
    $res->contact_phone = $contact_phone;
}

function initialize__Contact( & $res
    , $gender // gender_e
    , $name // string
    , $first_name // string
    , $birthday // basic_objects\Date
    , $notice // string
 )
{
    $res->gender = $gender;
    $res->name = $name;
    $res->first_name = $first_name;
    $res->birthday = $birthday;
    $res->notice = $notice;
}

function initialize__ExtendedContactInfo( & $res
    , $voice // voice_e
    , $lang // lang_tools\lang_e
    , $max_tries // uint32_t
    , $redial_if_no_feedback // bool
    , $time_window // basic_objects\TimeWindow
    , $weekdays // basic_objects\Weekdays
 )
{
    $res->voice = $voice;
    $res->lang = $lang;
    $res->max_tries = $max_tries;
    $res->redial_if_no_feedback = $redial_if_no_feedback;
    $res->time_window = $time_window;
    $res->weekdays = $weekdays;
}

function initialize__ReminderAction( & $res
    , $type // ReminderAction_type_e
    , $msg_templ_id // uint32_t
 )
{
    $res->type = $type;
    $res->msg_templ_id = $msg_templ_id;
}

function initialize__ReminderOptions( & $res
    , $voice // voice_e
    , $lang // lang_tools\lang_e
    , $max_tries // uint32_t
    , $redial_if_no_feedback // bool
    , $time_window // basic_objects\TimeWindow
    , $weekdays // basic_objects\Weekdays
 )
{
    $res->voice = $voice;
    $res->lang = $lang;
    $res->max_tries = $max_tries;
    $res->redial_if_no_feedback = $redial_if_no_feedback;
    $res->time_window = $time_window;
    $res->weekdays = $weekdays;
}

function initialize__Reminder( & $res
    , $msg_templ_id // uint32_t
    , $feedback_templ_id // uint32_t
    , $effective_time // uint32_t
    , $remind_period // uint32_t
    , $params // map<string, string>
    , $actions // map<dtmf_tools\tone_e, ReminderAction>
    , $options // ReminderOptions
 )
{
    $res->msg_templ_id = $msg_templ_id;
    $res->feedback_templ_id = $feedback_templ_id;
    $res->effective_time = $effective_time;
    $res->remind_period = $remind_period;
    $res->params = $params;
    $res->actions = $actions;
    $res->options = $options;
}

// base messages

function initialize__Request( & $res
    , $base_class_param_1 // string
 )
{
    // base class
    \generic_protocol\initialize__Request( $res, $base_class_param_1 );

}

function initialize__BackwardMessage( & $res
 )
{
    // no base class
}

// messages

function initialize__GetJobInfoRequest( & $res
    , $base_class_param_1 // string
    , $user_id // uint32_t
    , $job_ids // array<uint32_t>
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->user_id = $user_id;
    $res->job_ids = $job_ids;
}

function initialize__GetJobInfoResponse( & $res
    , $jobs // array<JobInfo>
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->jobs = $jobs;
}

function initialize__GetJobStatRequest( & $res
    , $base_class_param_1 // string
    , $user_id // uint32_t
    , $job_ids // array<uint32_t>
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->user_id = $user_id;
    $res->job_ids = $job_ids;
}

function initialize__GetJobStatResponse( & $res
    , $open_jobs // array<OpenJobStatus>
    , $closed_jobs // array<ClosedJobStatus>
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->open_jobs = $open_jobs;
    $res->closed_jobs = $closed_jobs;
}

function initialize__FindJobRequest( & $res
    , $base_class_param_1 // string
    , $user_id // uint32_t
    , $status // FindJobRequest_status_e
    , $contact_regex // string
    , $creation_time_range // basic_objects\TimeRange
    , $exec_time_range // basic_objects\TimeRange
    , $update_time_range // basic_objects\TimeRange
    , $max_results // uint32_t
    , $offset // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->user_id = $user_id;
    $res->status = $status;
    $res->contact_regex = $contact_regex;
    $res->creation_time_range = $creation_time_range;
    $res->exec_time_range = $exec_time_range;
    $res->update_time_range = $update_time_range;
    $res->max_results = $max_results;
    $res->offset = $offset;
}

function initialize__FindJobResponse( & $res
    , $total_size // uint32_t
    , $job_ids // array<uint32_t>
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->total_size = $total_size;
    $res->job_ids = $job_ids;
}

function initialize__FindTemplatesRequest( & $res
    , $base_class_param_1 // string
    , $user_id // uint32_t
    , $category_id // uint32_t
    , $name_regex // string
    , $lang // lang_tools\lang_e
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->user_id = $user_id;
    $res->category_id = $category_id;
    $res->name_regex = $name_regex;
    $res->lang = $lang;
}

function initialize__FindTemplatesResponse( & $res
    , $templates // array<TemplateInfo>
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->templates = $templates;
}

function initialize__CancelJobRequest( & $res
    , $base_class_param_1 // string
    , $job_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->job_id = $job_id;
}

function initialize__CancelJobResponse( & $res
 )
{
    // base class
    initialize__BackwardMessage( $res );

}

function initialize__CancelJobsRequest( & $res
    , $base_class_param_1 // string
    , $job_ids // array<uint32_t>
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->job_ids = $job_ids;
}

function initialize__CancelJobsResponse( & $res
    , $cancelled_job_ids // array<uint32_t>
    , $failed_jobs // array<CancellationFailureReason>
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->cancelled_job_ids = $cancelled_job_ids;
    $res->failed_jobs = $failed_jobs;
}

function initialize__SayRequest( & $res
    , $base_class_param_1 // string
    , $user_id // uint32_t
    , $contact_id // string
    , $msg_templ_id // uint32_t
    , $params // map<string, string>
    , $options // JobOptions
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->user_id = $user_id;
    $res->contact_id = $contact_id;
    $res->msg_templ_id = $msg_templ_id;
    $res->params = $params;
    $res->options = $options;
}

function initialize__SayResponse( & $res
    , $job_id // uint32_t
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->job_id = $job_id;
}

function initialize__SayFeedbackRequest( & $res
    , $base_class_param_1 // string
    , $user_id // uint32_t
    , $contact_id // string
    , $msg_templ_id // uint32_t
    , $feedback_templ_id // uint32_t
    , $params // map<string, string>
    , $actions // map<dtmf_tools\tone_e, Action>
    , $options // JobOptions
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->user_id = $user_id;
    $res->contact_id = $contact_id;
    $res->msg_templ_id = $msg_templ_id;
    $res->feedback_templ_id = $feedback_templ_id;
    $res->params = $params;
    $res->actions = $actions;
    $res->options = $options;
}

function initialize__SayFeedbackResponse( & $res
    , $job_id // uint32_t
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->job_id = $job_id;
}

function initialize__AddContactPhoneRequest( & $res
    , $base_class_param_1 // string
    , $contact_id // uint32_t
    , $contact_phone // ContactPhone
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->contact_id = $contact_id;
    $res->contact_phone = $contact_phone;
}

function initialize__AddContactPhoneResponse( & $res
    , $contact_phone_id // uint32_t
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->contact_phone_id = $contact_phone_id;
}

function initialize__ModifyContactPhoneRequest( & $res
    , $base_class_param_1 // string
    , $contact_phone_id // uint32_t
    , $contact_phone // ContactPhone
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->contact_phone_id = $contact_phone_id;
    $res->contact_phone = $contact_phone;
}

function initialize__ModifyContactPhoneResponse( & $res
 )
{
    // base class
    initialize__BackwardMessage( $res );

}

function initialize__DeleteContactPhoneRequest( & $res
    , $base_class_param_1 // string
    , $contact_phone_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->contact_phone_id = $contact_phone_id;
}

function initialize__DeleteContactPhoneResponse( & $res
 )
{
    // base class
    initialize__BackwardMessage( $res );

}

function initialize__GetContactPhoneRequest( & $res
    , $base_class_param_1 // string
    , $contact_phone_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->contact_phone_id = $contact_phone_id;
}

function initialize__GetContactPhoneResponse( & $res
    , $contact_id // uint32_t
    , $contact_phone // ContactPhone
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->contact_id = $contact_id;
    $res->contact_phone = $contact_phone;
}

function initialize__AddContactRequest( & $res
    , $base_class_param_1 // string
    , $user_id // uint32_t
    , $contact // Contact
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->user_id = $user_id;
    $res->contact = $contact;
}

function initialize__AddContactResponse( & $res
    , $contact_id // uint32_t
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->contact_id = $contact_id;
}

function initialize__ModifyContactRequest( & $res
    , $base_class_param_1 // string
    , $contact_id // uint32_t
    , $contact // Contact
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->contact_id = $contact_id;
    $res->contact = $contact;
}

function initialize__ModifyContactResponse( & $res
 )
{
    // base class
    initialize__BackwardMessage( $res );

}

function initialize__DeleteContactRequest( & $res
    , $base_class_param_1 // string
    , $contact_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->contact_id = $contact_id;
}

function initialize__DeleteContactResponse( & $res
 )
{
    // base class
    initialize__BackwardMessage( $res );

}

function initialize__GetContactRequest( & $res
    , $base_class_param_1 // string
    , $contact_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->contact_id = $contact_id;
}

function initialize__GetContactResponse( & $res
    , $contact // Contact
    , $contact_phone_ids // array<uint32_t>
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->contact = $contact;
    $res->contact_phone_ids = $contact_phone_ids;
}

function initialize__GetContactWithPhonesRequest( & $res
    , $base_class_param_1 // string
    , $contact_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->contact_id = $contact_id;
}

function initialize__GetContactWithPhonesResponse( & $res
    , $contact // Contact
    , $contact_phones // array<ContactPhoneWithId>
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->contact = $contact;
    $res->contact_phones = $contact_phones;
}

function initialize__GetContactExtRequest( & $res
    , $base_class_param_1 // string
    , $contact_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->contact_id = $contact_id;
}

function initialize__GetContactExtResponse( & $res
    , $contact // Contact
    , $contact_phones // array<ContactPhoneWithId>
    , $extended_info // ExtendedContactInfo
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->contact = $contact;
    $res->contact_phones = $contact_phones;
    $res->extended_info = $extended_info;
}

function initialize__GetExtendedContactInfoRequest( & $res
    , $base_class_param_1 // string
    , $contact_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->contact_id = $contact_id;
}

function initialize__GetExtendedContactInfoResponse( & $res
    , $extended_info // ExtendedContactInfo
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->extended_info = $extended_info;
}

function initialize__SetExtendedContactInfoRequest( & $res
    , $base_class_param_1 // string
    , $contact_id // uint32_t
    , $extended_info // ExtendedContactInfo
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->contact_id = $contact_id;
    $res->extended_info = $extended_info;
}

function initialize__SetExtendedContactInfoResponse( & $res
 )
{
    // base class
    initialize__BackwardMessage( $res );

}

function initialize__AddReminderRequest( & $res
    , $base_class_param_1 // string
    , $contact_phone_id // uint32_t
    , $reminder // Reminder
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->contact_phone_id = $contact_phone_id;
    $res->reminder = $reminder;
}

function initialize__AddReminderResponse( & $res
    , $job_id // uint32_t
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->job_id = $job_id;
}

function initialize__ModifyReminderRequest( & $res
    , $base_class_param_1 // string
    , $job_id // uint32_t
    , $contact_phone_id // uint32_t
    , $reminder // Reminder
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->job_id = $job_id;
    $res->contact_phone_id = $contact_phone_id;
    $res->reminder = $reminder;
}

function initialize__ModifyReminderResponse( & $res
 )
{
    // base class
    initialize__BackwardMessage( $res );

}

function initialize__GetReminderRequest( & $res
    , $base_class_param_1 // string
    , $job_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->job_id = $job_id;
}

function initialize__GetReminderResponse( & $res
    , $contact_id // uint32_t
    , $contact_phone_id // uint32_t
    , $contact_phone // string
    , $reminder // Reminder
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->contact_id = $contact_id;
    $res->contact_phone_id = $contact_phone_id;
    $res->contact_phone = $contact_phone;
    $res->reminder = $reminder;
}

function initialize__GetReminderStatusRequest( & $res
    , $base_class_param_1 // string
    , $user_id // uint32_t
    , $search_filter // string
    , $effective_date_time_range // basic_objects\TimeRange
    , $page_size // uint32_t
    , $page_number // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->user_id = $user_id;
    $res->search_filter = $search_filter;
    $res->effective_date_time_range = $effective_date_time_range;
    $res->page_size = $page_size;
    $res->page_number = $page_number;
}

// objects (constructors)

function create__JobOptions(
    $voice // voice_e
    , $urgency // urgency_e
    , $lang // lang_tools\lang_e
    , $exec_time // uint32_t
    , $max_tries // uint32_t
    , $redial_if_no_feedback // bool
    , $time_window // basic_objects\TimeWindow
    , $weekdays_mask // basic_objects\Weekdays
 )
{
    $res = new JobOptions;

    initialize__JobOptions( $res, $voice, $urgency, $lang, $exec_time, $max_tries, $redial_if_no_feedback, $time_window, $weekdays_mask );

    return $res;
}

function create__JobInfo(
    $job_id // uint32_t
    , $user_id // uint32_t
    , $type // JobInfo_type_e
    , $contact // string
    , $creation_time // uint32_t
    , $options // JobOptions
 )
{
    $res = new JobInfo;

    initialize__JobInfo( $res, $job_id, $user_id, $type, $contact, $creation_time, $options );

    return $res;
}

function create__ClosedJobStatus(
    $job_id // uint32_t
    , $exit_code // exit_status_e
    , $feedback // array<uint32_t>
    , $num_tries // uint32_t
    , $timestamp // uint32_t
    , $comment // string
 )
{
    $res = new ClosedJobStatus;

    initialize__ClosedJobStatus( $res, $job_id, $exit_code, $feedback, $num_tries, $timestamp, $comment );

    return $res;
}

function create__OpenJobStatus(
    $job_id // uint32_t
    , $state // OpenJobStatus_state_e
    , $current_try // uint32_t
    , $timestamp // uint32_t
    , $next_exec_time // uint32_t
 )
{
    $res = new OpenJobStatus;

    initialize__OpenJobStatus( $res, $job_id, $state, $current_try, $timestamp, $next_exec_time );

    return $res;
}

function create__TemplateInfo(
    $id // uint32_t
    , $category_id // uint32_t
    , $name // string
    , $lang // lang_tools\lang_e
    , $localized_name // string
    , $placeholders // array<string>
 )
{
    $res = new TemplateInfo;

    initialize__TemplateInfo( $res, $id, $category_id, $name, $lang, $localized_name, $placeholders );

    return $res;
}

function create__CancellationFailureReason(
    $job_id // uint32_t
    , $type // generic_protocol\ErrorResponse_type_e
    , $descr // string
 )
{
    $res = new CancellationFailureReason;

    initialize__CancellationFailureReason( $res, $job_id, $type, $descr );

    return $res;
}

function create__Action(
    $type // action_type_e
    , $msg_templ_id // uint32_t
 )
{
    $res = new Action;

    initialize__Action( $res, $type, $msg_templ_id );

    return $res;
}

function create__ContactPhone(
    $type // ContactPhone_type_e
    , $phone_number // string
 )
{
    $res = new ContactPhone;

    initialize__ContactPhone( $res, $type, $phone_number );

    return $res;
}

function create__ContactPhoneWithId(
    $contact_phone_id // uint32_t
    , $contact_phone // ContactPhone
 )
{
    $res = new ContactPhoneWithId;

    initialize__ContactPhoneWithId( $res, $contact_phone_id, $contact_phone );

    return $res;
}

function create__Contact(
    $gender // gender_e
    , $name // string
    , $first_name // string
    , $birthday // basic_objects\Date
    , $notice // string
 )
{
    $res = new Contact;

    initialize__Contact( $res, $gender, $name, $first_name, $birthday, $notice );

    return $res;
}

function create__ExtendedContactInfo(
    $voice // voice_e
    , $lang // lang_tools\lang_e
    , $max_tries // uint32_t
    , $redial_if_no_feedback // bool
    , $time_window // basic_objects\TimeWindow
    , $weekdays // basic_objects\Weekdays
 )
{
    $res = new ExtendedContactInfo;

    initialize__ExtendedContactInfo( $res, $voice, $lang, $max_tries, $redial_if_no_feedback, $time_window, $weekdays );

    return $res;
}

function create__ReminderAction(
    $type // ReminderAction_type_e
    , $msg_templ_id // uint32_t
 )
{
    $res = new ReminderAction;

    initialize__ReminderAction( $res, $type, $msg_templ_id );

    return $res;
}

function create__ReminderOptions(
    $voice // voice_e
    , $lang // lang_tools\lang_e
    , $max_tries // uint32_t
    , $redial_if_no_feedback // bool
    , $time_window // basic_objects\TimeWindow
    , $weekdays // basic_objects\Weekdays
 )
{
    $res = new ReminderOptions;

    initialize__ReminderOptions( $res, $voice, $lang, $max_tries, $redial_if_no_feedback, $time_window, $weekdays );

    return $res;
}

function create__Reminder(
    $msg_templ_id // uint32_t
    , $feedback_templ_id // uint32_t
    , $effective_time // uint32_t
    , $remind_period // uint32_t
    , $params // map<string, string>
    , $actions // map<dtmf_tools\tone_e, ReminderAction>
    , $options // ReminderOptions
 )
{
    $res = new Reminder;

    initialize__Reminder( $res, $msg_templ_id, $feedback_templ_id, $effective_time, $remind_period, $params, $actions, $options );

    return $res;
}

// messages (constructors)

function create__GetJobInfoRequest(
    $base_class_param_1 // string
    , $user_id // uint32_t
    , $job_ids // array<uint32_t>
 )
{
    $res = new GetJobInfoRequest;

    initialize__GetJobInfoRequest( $res, $base_class_param_1, $user_id, $job_ids );

    return $res;
}

function create__GetJobInfoResponse(
    $jobs // array<JobInfo>
 )
{
    $res = new GetJobInfoResponse;

    initialize__GetJobInfoResponse( $res, $jobs );

    return $res;
}

function create__GetJobStatRequest(
    $base_class_param_1 // string
    , $user_id // uint32_t
    , $job_ids // array<uint32_t>
 )
{
    $res = new GetJobStatRequest;

    initialize__GetJobStatRequest( $res, $base_class_param_1, $user_id, $job_ids );

    return $res;
}

function create__GetJobStatResponse(
    $open_jobs // array<OpenJobStatus>
    , $closed_jobs // array<ClosedJobStatus>
 )
{
    $res = new GetJobStatResponse;

    initialize__GetJobStatResponse( $res, $open_jobs, $closed_jobs );

    return $res;
}

function create__FindJobRequest(
    $base_class_param_1 // string
    , $user_id // uint32_t
    , $status // FindJobRequest_status_e
    , $contact_regex // string
    , $creation_time_range // basic_objects\TimeRange
    , $exec_time_range // basic_objects\TimeRange
    , $update_time_range // basic_objects\TimeRange
    , $max_results // uint32_t
    , $offset // uint32_t
 )
{
    $res = new FindJobRequest;

    initialize__FindJobRequest( $res, $base_class_param_1, $user_id, $status, $contact_regex, $creation_time_range, $exec_time_range, $update_time_range, $max_results, $offset );

    return $res;
}

function create__FindJobResponse(
    $total_size // uint32_t
    , $job_ids // array<uint32_t>
 )
{
    $res = new FindJobResponse;

    initialize__FindJobResponse( $res, $total_size, $job_ids );

    return $res;
}

function create__FindTemplatesRequest(
    $base_class_param_1 // string
    , $user_id // uint32_t
    , $category_id // uint32_t
    , $name_regex // string
    , $lang // lang_tools\lang_e
 )
{
    $res = new FindTemplatesRequest;

    initialize__FindTemplatesRequest( $res, $base_class_param_1, $user_id, $category_id, $name_regex, $lang );

    return $res;
}

function create__FindTemplatesResponse(
    $templates // array<TemplateInfo>
 )
{
    $res = new FindTemplatesResponse;

    initialize__FindTemplatesResponse( $res, $templates );

    return $res;
}

function create__CancelJobRequest(
    $base_class_param_1 // string
    , $job_id // uint32_t
 )
{
    $res = new CancelJobRequest;

    initialize__CancelJobRequest( $res, $base_class_param_1, $job_id );

    return $res;
}

function create__CancelJobResponse(
 )
{
    $res = new CancelJobResponse;

    initialize__CancelJobResponse( $res );

    return $res;
}

function create__CancelJobsRequest(
    $base_class_param_1 // string
    , $job_ids // array<uint32_t>
 )
{
    $res = new CancelJobsRequest;

    initialize__CancelJobsRequest( $res, $base_class_param_1, $job_ids );

    return $res;
}

function create__CancelJobsResponse(
    $cancelled_job_ids // array<uint32_t>
    , $failed_jobs // array<CancellationFailureReason>
 )
{
    $res = new CancelJobsResponse;

    initialize__CancelJobsResponse( $res, $cancelled_job_ids, $failed_jobs );

    return $res;
}

function create__SayRequest(
    $base_class_param_1 // string
    , $user_id // uint32_t
    , $contact_id // string
    , $msg_templ_id // uint32_t
    , $params // map<string, string>
    , $options // JobOptions
 )
{
    $res = new SayRequest;

    initialize__SayRequest( $res, $base_class_param_1, $user_id, $contact_id, $msg_templ_id, $params, $options );

    return $res;
}

function create__SayResponse(
    $job_id // uint32_t
 )
{
    $res = new SayResponse;

    initialize__SayResponse( $res, $job_id );

    return $res;
}

function create__SayFeedbackRequest(
    $base_class_param_1 // string
    , $user_id // uint32_t
    , $contact_id // string
    , $msg_templ_id // uint32_t
    , $feedback_templ_id // uint32_t
    , $params // map<string, string>
    , $actions // map<dtmf_tools\tone_e, Action>
    , $options // JobOptions
 )
{
    $res = new SayFeedbackRequest;

    initialize__SayFeedbackRequest( $res, $base_class_param_1, $user_id, $contact_id, $msg_templ_id, $feedback_templ_id, $params, $actions, $options );

    return $res;
}

function create__SayFeedbackResponse(
    $job_id // uint32_t
 )
{
    $res = new SayFeedbackResponse;

    initialize__SayFeedbackResponse( $res, $job_id );

    return $res;
}

function create__AddContactPhoneRequest(
    $base_class_param_1 // string
    , $contact_id // uint32_t
    , $contact_phone // ContactPhone
 )
{
    $res = new AddContactPhoneRequest;

    initialize__AddContactPhoneRequest( $res, $base_class_param_1, $contact_id, $contact_phone );

    return $res;
}

function create__AddContactPhoneResponse(
    $contact_phone_id // uint32_t
 )
{
    $res = new AddContactPhoneResponse;

    initialize__AddContactPhoneResponse( $res, $contact_phone_id );

    return $res;
}

function create__ModifyContactPhoneRequest(
    $base_class_param_1 // string
    , $contact_phone_id // uint32_t
    , $contact_phone // ContactPhone
 )
{
    $res = new ModifyContactPhoneRequest;

    initialize__ModifyContactPhoneRequest( $res, $base_class_param_1, $contact_phone_id, $contact_phone );

    return $res;
}

function create__ModifyContactPhoneResponse(
 )
{
    $res = new ModifyContactPhoneResponse;

    initialize__ModifyContactPhoneResponse( $res );

    return $res;
}

function create__DeleteContactPhoneRequest(
    $base_class_param_1 // string
    , $contact_phone_id // uint32_t
 )
{
    $res = new DeleteContactPhoneRequest;

    initialize__DeleteContactPhoneRequest( $res, $base_class_param_1, $contact_phone_id );

    return $res;
}

function create__DeleteContactPhoneResponse(
 )
{
    $res = new DeleteContactPhoneResponse;

    initialize__DeleteContactPhoneResponse( $res );

    return $res;
}

function create__GetContactPhoneRequest(
    $base_class_param_1 // string
    , $contact_phone_id // uint32_t
 )
{
    $res = new GetContactPhoneRequest;

    initialize__GetContactPhoneRequest( $res, $base_class_param_1, $contact_phone_id );

    return $res;
}

function create__GetContactPhoneResponse(
    $contact_id // uint32_t
    , $contact_phone // ContactPhone
 )
{
    $res = new GetContactPhoneResponse;

    initialize__GetContactPhoneResponse( $res, $contact_id, $contact_phone );

    return $res;
}

function create__AddContactRequest(
    $base_class_param_1 // string
    , $user_id // uint32_t
    , $contact // Contact
 )
{
    $res = new AddContactRequest;

    initialize__AddContactRequest( $res, $base_class_param_1, $user_id, $contact );

    return $res;
}

function create__AddContactResponse(
    $contact_id // uint32_t
 )
{
    $res = new AddContactResponse;

    initialize__AddContactResponse( $res, $contact_id );

    return $res;
}

function create__ModifyContactRequest(
    $base_class_param_1 // string
    , $contact_id // uint32_t
    , $contact // Contact
 )
{
    $res = new ModifyContactRequest;

    initialize__ModifyContactRequest( $res, $base_class_param_1, $contact_id, $contact );

    return $res;
}

function create__ModifyContactResponse(
 )
{
    $res = new ModifyContactResponse;

    initialize__ModifyContactResponse( $res );

    return $res;
}

function create__DeleteContactRequest(
    $base_class_param_1 // string
    , $contact_id // uint32_t
 )
{
    $res = new DeleteContactRequest;

    initialize__DeleteContactRequest( $res, $base_class_param_1, $contact_id );

    return $res;
}

function create__DeleteContactResponse(
 )
{
    $res = new DeleteContactResponse;

    initialize__DeleteContactResponse( $res );

    return $res;
}

function create__GetContactRequest(
    $base_class_param_1 // string
    , $contact_id // uint32_t
 )
{
    $res = new GetContactRequest;

    initialize__GetContactRequest( $res, $base_class_param_1, $contact_id );

    return $res;
}

function create__GetContactResponse(
    $contact // Contact
    , $contact_phone_ids // array<uint32_t>
 )
{
    $res = new GetContactResponse;

    initialize__GetContactResponse( $res, $contact, $contact_phone_ids );

    return $res;
}

function create__GetContactWithPhonesRequest(
    $base_class_param_1 // string
    , $contact_id // uint32_t
 )
{
    $res = new GetContactWithPhonesRequest;

    initialize__GetContactWithPhonesRequest( $res, $base_class_param_1, $contact_id );

    return $res;
}

function create__GetContactWithPhonesResponse(
    $contact // Contact
    , $contact_phones // array<ContactPhoneWithId>
 )
{
    $res = new GetContactWithPhonesResponse;

    initialize__GetContactWithPhonesResponse( $res, $contact, $contact_phones );

    return $res;
}

function create__GetContactExtRequest(
    $base_class_param_1 // string
    , $contact_id // uint32_t
 )
{
    $res = new GetContactExtRequest;

    initialize__GetContactExtRequest( $res, $base_class_param_1, $contact_id );

    return $res;
}

function create__GetContactExtResponse(
    $contact // Contact
    , $contact_phones // array<ContactPhoneWithId>
    , $extended_info // ExtendedContactInfo
 )
{
    $res = new GetContactExtResponse;

    initialize__GetContactExtResponse( $res, $contact, $contact_phones, $extended_info );

    return $res;
}

function create__GetExtendedContactInfoRequest(
    $base_class_param_1 // string
    , $contact_id // uint32_t
 )
{
    $res = new GetExtendedContactInfoRequest;

    initialize__GetExtendedContactInfoRequest( $res, $base_class_param_1, $contact_id );

    return $res;
}

function create__GetExtendedContactInfoResponse(
    $extended_info // ExtendedContactInfo
 )
{
    $res = new GetExtendedContactInfoResponse;

    initialize__GetExtendedContactInfoResponse( $res, $extended_info );

    return $res;
}

function create__SetExtendedContactInfoRequest(
    $base_class_param_1 // string
    , $contact_id // uint32_t
    , $extended_info // ExtendedContactInfo
 )
{
    $res = new SetExtendedContactInfoRequest;

    initialize__SetExtendedContactInfoRequest( $res, $base_class_param_1, $contact_id, $extended_info );

    return $res;
}

function create__SetExtendedContactInfoResponse(
 )
{
    $res = new SetExtendedContactInfoResponse;

    initialize__SetExtendedContactInfoResponse( $res );

    return $res;
}

function create__AddReminderRequest(
    $base_class_param_1 // string
    , $contact_phone_id // uint32_t
    , $reminder // Reminder
 )
{
    $res = new AddReminderRequest;

    initialize__AddReminderRequest( $res, $base_class_param_1, $contact_phone_id, $reminder );

    return $res;
}

function create__AddReminderResponse(
    $job_id // uint32_t
 )
{
    $res = new AddReminderResponse;

    initialize__AddReminderResponse( $res, $job_id );

    return $res;
}

function create__ModifyReminderRequest(
    $base_class_param_1 // string
    , $job_id // uint32_t
    , $contact_phone_id // uint32_t
    , $reminder // Reminder
 )
{
    $res = new ModifyReminderRequest;

    initialize__ModifyReminderRequest( $res, $base_class_param_1, $job_id, $contact_phone_id, $reminder );

    return $res;
}

function create__ModifyReminderResponse(
 )
{
    $res = new ModifyReminderResponse;

    initialize__ModifyReminderResponse( $res );

    return $res;
}

function create__GetReminderRequest(
    $base_class_param_1 // string
    , $job_id // uint32_t
 )
{
    $res = new GetReminderRequest;

    initialize__GetReminderRequest( $res, $base_class_param_1, $job_id );

    return $res;
}

function create__GetReminderResponse(
    $contact_id // uint32_t
    , $contact_phone_id // uint32_t
    , $contact_phone // string
    , $reminder // Reminder
 )
{
    $res = new GetReminderResponse;

    initialize__GetReminderResponse( $res, $contact_id, $contact_phone_id, $contact_phone, $reminder );

    return $res;
}

function create__GetReminderStatusRequest(
    $base_class_param_1 // string
    , $user_id // uint32_t
    , $search_filter // string
    , $effective_date_time_range // basic_objects\TimeRange
    , $page_size // uint32_t
    , $page_number // uint32_t
 )
{
    $res = new GetReminderStatusRequest;

    initialize__GetReminderStatusRequest( $res, $base_class_param_1, $user_id, $search_filter, $effective_date_time_range, $page_size, $page_number );

    return $res;
}

# namespace_end persek_protocol


?>
