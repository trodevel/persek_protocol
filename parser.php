<?php

namespace persek_protocol;


// includes
require_once __DIR__.'/../generic_protocol/parser.php';
require_once __DIR__.'/../basic_objects/parser.php';
require_once __DIR__.'/../dtmf_tools_protocol/parser.php';
require_once __DIR__.'/../lang_tools_protocol/parser.php';
require_once __DIR__.'/../basic_parser/parser.php';

// enums

function parse__voice_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__urgency_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__JobInfo_type_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__exit_status_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__OpenJobStatus_state_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__FindJobRequest_status_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__action_type_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__ContactPhone_type_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__gender_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__ReminderAction_type_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

// objects

function parse__JobOptions( & $csv_arr, & $offset )
{
    $res = new JobOptions;

    $res->voice = parse__voice_e( $csv_arr, $offset );
    $res->urgency = parse__urgency_e( $csv_arr, $offset );
    $res->lang = \lang_tools\parse__lang_e( $csv_arr, $offset );
    $res->exec_time = \basic_parser\parse__int( $csv_arr, $offset );
    $res->max_tries = \basic_parser\parse__int( $csv_arr, $offset );
    $res->redial_if_no_feedback = \basic_parser\parse__bool( $csv_arr, $offset );
    $res->time_window = \basic_objects\parse__TimeWindow( $csv_arr, $offset );
    $res->weekdays_mask = \basic_objects\parse__Weekdays( $csv_arr, $offset );

    return $res;
}

function parse__JobInfo( & $csv_arr, & $offset )
{
    $res = new JobInfo;

    $res->job_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->type = parse__JobInfo_type_e( $csv_arr, $offset );
    $res->contact = \basic_parser\parse__string( $csv_arr, $offset );
    $res->creation_time = \basic_parser\parse__int( $csv_arr, $offset );
    $res->options = parse__JobOptions( $csv_arr, $offset );

    return $res;
}

function parse__ClosedJobStatus( & $csv_arr, & $offset )
{
    $res = new ClosedJobStatus;

    $res->job_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->exit_code = parse__exit_status_e( $csv_arr, $offset );
    $res->feedback = \basic_parser\parse__vector( $csv_arr, $offset, '\basic_parser\parse__int' ); // Array
    $res->num_tries = \basic_parser\parse__int( $csv_arr, $offset );
    $res->timestamp = \basic_parser\parse__int( $csv_arr, $offset );
    $res->comment = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__OpenJobStatus( & $csv_arr, & $offset )
{
    $res = new OpenJobStatus;

    $res->job_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->state = parse__OpenJobStatus_state_e( $csv_arr, $offset );
    $res->current_try = \basic_parser\parse__int( $csv_arr, $offset );
    $res->timestamp = \basic_parser\parse__int( $csv_arr, $offset );
    $res->next_exec_time = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__TemplateInfo( & $csv_arr, & $offset )
{
    $res = new TemplateInfo;

    $res->id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->category_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->name = \basic_parser\parse__string( $csv_arr, $offset );
    $res->lang = \lang_tools\parse__lang_e( $csv_arr, $offset );
    $res->localized_name = \basic_parser\parse__string( $csv_arr, $offset );
    $res->placeholders = \basic_parser\parse__vector( $csv_arr, $offset, '\basic_parser\parse__string' ); // Array

    return $res;
}

function parse__CancellationFailureReason( & $csv_arr, & $offset )
{
    $res = new CancellationFailureReason;

    $res->job_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->type = \generic_protocol\parse__ErrorResponse_type_e( $csv_arr, $offset );
    $res->descr = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__Action( & $csv_arr, & $offset )
{
    $res = new Action;

    $res->type = parse__action_type_e( $csv_arr, $offset );
    $res->msg_templ_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__ContactPhone( & $csv_arr, & $offset )
{
    $res = new ContactPhone;

    $res->type = parse__ContactPhone_type_e( $csv_arr, $offset );
    $res->phone_number = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__ContactPhoneWithId( & $csv_arr, & $offset )
{
    $res = new ContactPhoneWithId;

    $res->contact_phone_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->contact_phone = parse__ContactPhone( $csv_arr, $offset );

    return $res;
}

function parse__Contact( & $csv_arr, & $offset )
{
    $res = new Contact;

    $res->gender = parse__gender_e( $csv_arr, $offset );
    $res->name = \basic_parser\parse__string( $csv_arr, $offset );
    $res->first_name = \basic_parser\parse__string( $csv_arr, $offset );
    $res->birthday = \basic_objects\parse__Date( $csv_arr, $offset );
    $res->notice = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__ExtendedContactInfo( & $csv_arr, & $offset )
{
    $res = new ExtendedContactInfo;

    $res->voice = parse__voice_e( $csv_arr, $offset );
    $res->lang = \lang_tools\parse__lang_e( $csv_arr, $offset );
    $res->max_tries = \basic_parser\parse__int( $csv_arr, $offset );
    $res->redial_if_no_feedback = \basic_parser\parse__bool( $csv_arr, $offset );
    $res->time_window = \basic_objects\parse__TimeWindow( $csv_arr, $offset );
    $res->weekdays = \basic_objects\parse__Weekdays( $csv_arr, $offset );

    return $res;
}

function parse__ReminderAction( & $csv_arr, & $offset )
{
    $res = new ReminderAction;

    $res->type = parse__ReminderAction_type_e( $csv_arr, $offset );
    $res->msg_templ_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__ReminderOptions( & $csv_arr, & $offset )
{
    $res = new ReminderOptions;

    $res->voice = parse__voice_e( $csv_arr, $offset );
    $res->lang = \lang_tools\parse__lang_e( $csv_arr, $offset );
    $res->max_tries = \basic_parser\parse__int( $csv_arr, $offset );
    $res->redial_if_no_feedback = \basic_parser\parse__bool( $csv_arr, $offset );
    $res->time_window = \basic_objects\parse__TimeWindow( $csv_arr, $offset );
    $res->weekdays = \basic_objects\parse__Weekdays( $csv_arr, $offset );

    return $res;
}

function parse__Reminder( & $csv_arr, & $offset )
{
    $res = new Reminder;

    $res->msg_templ_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->feedback_templ_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->effective_time = \basic_parser\parse__int( $csv_arr, $offset );
    $res->remind_period = \basic_parser\parse__int( $csv_arr, $offset );
    $res->params = \basic_parser\parse__map( $csv_arr, $offset, '\basic_parser\parse__string', '\basic_parser\parse__string' ); // Map
    $res->actions = \basic_parser\parse__map( $csv_arr, $offset, '\dtmf_tools\parse__tone_e', '\persek_protocol\parse__ReminderAction' ); // Map
    $res->options = parse__ReminderOptions( $csv_arr, $offset );

    return $res;
}

// base messages

function parse__Request( & $res, & $csv_arr, & $offset )
{
    // base class
    \generic_protocol\parse__Request( $res, $csv_arr, $offset );


}

function parse__BackwardMessage( & $res, & $csv_arr, & $offset )
{
    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );


}

// messages

function parse__GetJobInfoRequest( & $csv_arr )
{
    $res = new GetJobInfoRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->job_ids = \basic_parser\parse__vector( $csv_arr, $offset, '\basic_parser\parse__int' ); // Array

    return $res;
}

function parse__GetJobInfoResponse( & $csv_arr )
{
    $res = new GetJobInfoResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->jobs = \basic_parser\parse__vector( $csv_arr, $offset, '\persek_protocol\parse__JobInfo' ); // Array

    return $res;
}

function parse__GetJobStatRequest( & $csv_arr )
{
    $res = new GetJobStatRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->job_ids = \basic_parser\parse__vector( $csv_arr, $offset, '\basic_parser\parse__int' ); // Array

    return $res;
}

function parse__GetJobStatResponse( & $csv_arr )
{
    $res = new GetJobStatResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->open_jobs = \basic_parser\parse__vector( $csv_arr, $offset, '\persek_protocol\parse__OpenJobStatus' ); // Array
    $res->closed_jobs = \basic_parser\parse__vector( $csv_arr, $offset, '\persek_protocol\parse__ClosedJobStatus' ); // Array

    return $res;
}

function parse__FindJobRequest( & $csv_arr )
{
    $res = new FindJobRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->status = parse__FindJobRequest_status_e( $csv_arr, $offset );
    $res->contact_regex = \basic_parser\parse__string( $csv_arr, $offset );
    $res->creation_time_range = \basic_objects\parse__TimeRange( $csv_arr, $offset );
    $res->exec_time_range = \basic_objects\parse__TimeRange( $csv_arr, $offset );
    $res->update_time_range = \basic_objects\parse__TimeRange( $csv_arr, $offset );
    $res->max_results = \basic_parser\parse__int( $csv_arr, $offset );
    $res->offset = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__FindJobResponse( & $csv_arr )
{
    $res = new FindJobResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->total_size = \basic_parser\parse__int( $csv_arr, $offset );
    $res->job_ids = \basic_parser\parse__vector( $csv_arr, $offset, '\basic_parser\parse__int' ); // Array

    return $res;
}

function parse__FindTemplatesRequest( & $csv_arr )
{
    $res = new FindTemplatesRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->category_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->name_regex = \basic_parser\parse__string( $csv_arr, $offset );
    $res->lang = \lang_tools\parse__lang_e( $csv_arr, $offset );

    return $res;
}

function parse__FindTemplatesResponse( & $csv_arr )
{
    $res = new FindTemplatesResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->templates = \basic_parser\parse__vector( $csv_arr, $offset, '\persek_protocol\parse__TemplateInfo' ); // Array

    return $res;
}

function parse__CancelJobRequest( & $csv_arr )
{
    $res = new CancelJobRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->job_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__CancelJobResponse( & $csv_arr )
{
    $res = new CancelJobResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__CancelJobsRequest( & $csv_arr )
{
    $res = new CancelJobsRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->job_ids = \basic_parser\parse__vector( $csv_arr, $offset, '\basic_parser\parse__int' ); // Array

    return $res;
}

function parse__CancelJobsResponse( & $csv_arr )
{
    $res = new CancelJobsResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->cancelled_job_ids = \basic_parser\parse__vector( $csv_arr, $offset, '\basic_parser\parse__int' ); // Array
    $res->failed_jobs = \basic_parser\parse__vector( $csv_arr, $offset, '\persek_protocol\parse__CancellationFailureReason' ); // Array

    return $res;
}

function parse__SayRequest( & $csv_arr )
{
    $res = new SayRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->contact_id = \basic_parser\parse__string( $csv_arr, $offset );
    $res->msg_templ_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->params = \basic_parser\parse__map( $csv_arr, $offset, '\basic_parser\parse__string', '\basic_parser\parse__string' ); // Map
    $res->options = parse__JobOptions( $csv_arr, $offset );

    return $res;
}

function parse__SayResponse( & $csv_arr )
{
    $res = new SayResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->job_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__SayFeedbackRequest( & $csv_arr )
{
    $res = new SayFeedbackRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->contact_id = \basic_parser\parse__string( $csv_arr, $offset );
    $res->msg_templ_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->feedback_templ_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->params = \basic_parser\parse__map( $csv_arr, $offset, '\basic_parser\parse__string', '\basic_parser\parse__string' ); // Map
    $res->actions = \basic_parser\parse__map( $csv_arr, $offset, '\dtmf_tools\parse__tone_e', '\persek_protocol\parse__Action' ); // Map
    $res->options = parse__JobOptions( $csv_arr, $offset );

    return $res;
}

function parse__SayFeedbackResponse( & $csv_arr )
{
    $res = new SayFeedbackResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->job_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__AddContactPhoneRequest( & $csv_arr )
{
    $res = new AddContactPhoneRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->contact_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->contact_phone = parse__ContactPhone( $csv_arr, $offset );

    return $res;
}

function parse__AddContactPhoneResponse( & $csv_arr )
{
    $res = new AddContactPhoneResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->contact_phone_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__ModifyContactPhoneRequest( & $csv_arr )
{
    $res = new ModifyContactPhoneRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->contact_phone_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->contact_phone = parse__ContactPhone( $csv_arr, $offset );

    return $res;
}

function parse__ModifyContactPhoneResponse( & $csv_arr )
{
    $res = new ModifyContactPhoneResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__DeleteContactPhoneRequest( & $csv_arr )
{
    $res = new DeleteContactPhoneRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->contact_phone_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__DeleteContactPhoneResponse( & $csv_arr )
{
    $res = new DeleteContactPhoneResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__GetContactPhoneRequest( & $csv_arr )
{
    $res = new GetContactPhoneRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->contact_phone_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__GetContactPhoneResponse( & $csv_arr )
{
    $res = new GetContactPhoneResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->contact_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->contact_phone = parse__ContactPhone( $csv_arr, $offset );

    return $res;
}

function parse__AddContactRequest( & $csv_arr )
{
    $res = new AddContactRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->contact = parse__Contact( $csv_arr, $offset );

    return $res;
}

function parse__AddContactResponse( & $csv_arr )
{
    $res = new AddContactResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->contact_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__ModifyContactRequest( & $csv_arr )
{
    $res = new ModifyContactRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->contact_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->contact = parse__Contact( $csv_arr, $offset );

    return $res;
}

function parse__ModifyContactResponse( & $csv_arr )
{
    $res = new ModifyContactResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__DeleteContactRequest( & $csv_arr )
{
    $res = new DeleteContactRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->contact_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__DeleteContactResponse( & $csv_arr )
{
    $res = new DeleteContactResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__GetContactRequest( & $csv_arr )
{
    $res = new GetContactRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->contact_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__GetContactResponse( & $csv_arr )
{
    $res = new GetContactResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->contact = parse__Contact( $csv_arr, $offset );
    $res->contact_phone_ids = \basic_parser\parse__vector( $csv_arr, $offset, '\basic_parser\parse__int' ); // Array

    return $res;
}

function parse__GetContactWithPhonesRequest( & $csv_arr )
{
    $res = new GetContactWithPhonesRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->contact_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__GetContactWithPhonesResponse( & $csv_arr )
{
    $res = new GetContactWithPhonesResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->contact = parse__Contact( $csv_arr, $offset );
    $res->contact_phones = \basic_parser\parse__vector( $csv_arr, $offset, '\persek_protocol\parse__ContactPhoneWithId' ); // Array

    return $res;
}

function parse__GetContactExtRequest( & $csv_arr )
{
    $res = new GetContactExtRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->contact_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__GetContactExtResponse( & $csv_arr )
{
    $res = new GetContactExtResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->contact = parse__Contact( $csv_arr, $offset );
    $res->contact_phones = \basic_parser\parse__vector( $csv_arr, $offset, '\persek_protocol\parse__ContactPhoneWithId' ); // Array
    $res->extended_info = parse__ExtendedContactInfo( $csv_arr, $offset );

    return $res;
}

function parse__GetExtendedContactInfoRequest( & $csv_arr )
{
    $res = new GetExtendedContactInfoRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->contact_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__GetExtendedContactInfoResponse( & $csv_arr )
{
    $res = new GetExtendedContactInfoResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->extended_info = parse__ExtendedContactInfo( $csv_arr, $offset );

    return $res;
}

function parse__SetExtendedContactInfoRequest( & $csv_arr )
{
    $res = new SetExtendedContactInfoRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->contact_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->extended_info = parse__ExtendedContactInfo( $csv_arr, $offset );

    return $res;
}

function parse__SetExtendedContactInfoResponse( & $csv_arr )
{
    $res = new SetExtendedContactInfoResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__AddReminderRequest( & $csv_arr )
{
    $res = new AddReminderRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->contact_phone_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->reminder = parse__Reminder( $csv_arr, $offset );

    return $res;
}

function parse__AddReminderResponse( & $csv_arr )
{
    $res = new AddReminderResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->job_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__ModifyReminderRequest( & $csv_arr )
{
    $res = new ModifyReminderRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->job_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->contact_phone_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->reminder = parse__Reminder( $csv_arr, $offset );

    return $res;
}

function parse__ModifyReminderResponse( & $csv_arr )
{
    $res = new ModifyReminderResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__GetReminderRequest( & $csv_arr )
{
    $res = new GetReminderRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->job_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__GetReminderResponse( & $csv_arr )
{
    $res = new GetReminderResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->contact_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->contact_phone_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->contact_phone = \basic_parser\parse__string( $csv_arr, $offset );
    $res->reminder = parse__Reminder( $csv_arr, $offset );

    return $res;
}

function parse__GetReminderStatusRequest( & $csv_arr )
{
    $res = new GetReminderStatusRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->search_filter = \basic_parser\parse__string( $csv_arr, $offset );
    $res->effective_date_time_range = \basic_objects\parse__TimeRange( $csv_arr, $offset );
    $res->page_size = \basic_parser\parse__int( $csv_arr, $offset );
    $res->page_number = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

// generic

class Parser extends \generic_protocol\Parser
{

protected static function parse_csv_array( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return NULL;

    $handler_map = array(
        // messages
        'persek/GetJobInfoRequest'         => 'parse__GetJobInfoRequest',
        'persek/GetJobInfoResponse'         => 'parse__GetJobInfoResponse',
        'persek/GetJobStatRequest'         => 'parse__GetJobStatRequest',
        'persek/GetJobStatResponse'         => 'parse__GetJobStatResponse',
        'persek/FindJobRequest'         => 'parse__FindJobRequest',
        'persek/FindJobResponse'         => 'parse__FindJobResponse',
        'persek/FindTemplatesRequest'         => 'parse__FindTemplatesRequest',
        'persek/FindTemplatesResponse'         => 'parse__FindTemplatesResponse',
        'persek/CancelJobRequest'         => 'parse__CancelJobRequest',
        'persek/CancelJobResponse'         => 'parse__CancelJobResponse',
        'persek/CancelJobsRequest'         => 'parse__CancelJobsRequest',
        'persek/CancelJobsResponse'         => 'parse__CancelJobsResponse',
        'persek/SayRequest'         => 'parse__SayRequest',
        'persek/SayResponse'         => 'parse__SayResponse',
        'persek/SayFeedbackRequest'         => 'parse__SayFeedbackRequest',
        'persek/SayFeedbackResponse'         => 'parse__SayFeedbackResponse',
        'persek/AddContactPhoneRequest'         => 'parse__AddContactPhoneRequest',
        'persek/AddContactPhoneResponse'         => 'parse__AddContactPhoneResponse',
        'persek/ModifyContactPhoneRequest'         => 'parse__ModifyContactPhoneRequest',
        'persek/ModifyContactPhoneResponse'         => 'parse__ModifyContactPhoneResponse',
        'persek/DeleteContactPhoneRequest'         => 'parse__DeleteContactPhoneRequest',
        'persek/DeleteContactPhoneResponse'         => 'parse__DeleteContactPhoneResponse',
        'persek/GetContactPhoneRequest'         => 'parse__GetContactPhoneRequest',
        'persek/GetContactPhoneResponse'         => 'parse__GetContactPhoneResponse',
        'persek/AddContactRequest'         => 'parse__AddContactRequest',
        'persek/AddContactResponse'         => 'parse__AddContactResponse',
        'persek/ModifyContactRequest'         => 'parse__ModifyContactRequest',
        'persek/ModifyContactResponse'         => 'parse__ModifyContactResponse',
        'persek/DeleteContactRequest'         => 'parse__DeleteContactRequest',
        'persek/DeleteContactResponse'         => 'parse__DeleteContactResponse',
        'persek/GetContactRequest'         => 'parse__GetContactRequest',
        'persek/GetContactResponse'         => 'parse__GetContactResponse',
        'persek/GetContactWithPhonesRequest'         => 'parse__GetContactWithPhonesRequest',
        'persek/GetContactWithPhonesResponse'         => 'parse__GetContactWithPhonesResponse',
        'persek/GetContactExtRequest'         => 'parse__GetContactExtRequest',
        'persek/GetContactExtResponse'         => 'parse__GetContactExtResponse',
        'persek/GetExtendedContactInfoRequest'         => 'parse__GetExtendedContactInfoRequest',
        'persek/GetExtendedContactInfoResponse'         => 'parse__GetExtendedContactInfoResponse',
        'persek/SetExtendedContactInfoRequest'         => 'parse__SetExtendedContactInfoRequest',
        'persek/SetExtendedContactInfoResponse'         => 'parse__SetExtendedContactInfoResponse',
        'persek/AddReminderRequest'         => 'parse__AddReminderRequest',
        'persek/AddReminderResponse'         => 'parse__AddReminderResponse',
        'persek/ModifyReminderRequest'         => 'parse__ModifyReminderRequest',
        'persek/ModifyReminderResponse'         => 'parse__ModifyReminderResponse',
        'persek/GetReminderRequest'         => 'parse__GetReminderRequest',
        'persek/GetReminderResponse'         => 'parse__GetReminderResponse',
        'persek/GetReminderStatusRequest'         => 'parse__GetReminderStatusRequest',
    );

    $type = $csv_arr[0][0];

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\persek_protocol\\' . $handler_map[ $type ];
        return $func( $csv_arr[0] );
    }

    return \generic_protocol\Parser::parse_csv_array( $csv_arr );
}

}

# namespace_end persek_protocol


?>
