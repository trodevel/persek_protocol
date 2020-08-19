<?php

namespace persek_protocol;


// includes
require_once __DIR__.'/../generic_protocol/request_encoder.php';
require_once __DIR__.'/../basic_objects/request_encoder.php';
require_once __DIR__.'/../dtmf_tools_protocol/request_encoder.php';
require_once __DIR__.'/../lang_tools_protocol/request_encoder.php';
require_once __DIR__.'/../basic_parser/request_encoder.php';

// enums

function to_generic_request__voice_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

function to_generic_request__urgency_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

function to_generic_request__JobInfo_type_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

function to_generic_request__exit_status_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

function to_generic_request__OpenJobStatus_state_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

function to_generic_request__FindJobRequest_status_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

function to_generic_request__action_type_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

function to_generic_request__ContactPhone_type_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

function to_generic_request__gender_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

function to_generic_request__ReminderAction_type_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

// objects

function to_generic_request__JobOptions( $prefix, & $r )
{
    $res = "";
    $res .= "&" . to_generic_request__voice_e( $prefix . ".VOICE", $r->voice );
    $res .= "&" . to_generic_request__urgency_e( $prefix . ".URGENCY", $r->urgency );
    $res .= "&" . \lang_tools\to_generic_request__lang_e( $prefix . ".LANG", $r->lang );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".EXEC_TIME", $r->exec_time );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".MAX_TRIES", $r->max_tries );
    $res .= "&" . \basic_parser\to_generic_request__bool( $prefix . ".REDIAL_IF_NO_FEEDBACK", $r->redial_if_no_feedback );
    $res .= "&" . \basic_objects\to_generic_request__TimeWindow( $prefix . ".TIME_WINDOW", $r->time_window );
    $res .= "&" . \basic_objects\to_generic_request__Weekdays( $prefix . ".WEEKDAYS_MASK", $r->weekdays_mask );

    return $res;
}

function to_generic_request__JobInfo( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".JOB_ID", $r->job_id );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".USER_ID", $r->user_id );
    $res .= "&" . to_generic_request__JobInfo_type_e( $prefix . ".TYPE", $r->type );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".CONTACT", $r->contact );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".CREATION_TIME", $r->creation_time );
    $res .= "&" . to_generic_request__JobOptions( $prefix . ".OPTIONS", $r->options );

    return $res;
}

function to_generic_request__ClosedJobStatus( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".JOB_ID", $r->job_id );
    $res .= "&" . to_generic_request__exit_status_e( $prefix . ".EXIT_CODE", $r->exit_code );
    $res .= "&" . \basic_parser\to_generic_request__vector( $prefix . ".FEEDBACK", $r->feedback, '\basic_parser\to_generic_request__int' ); // Array
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".NUM_TRIES", $r->num_tries );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".TIMESTAMP", $r->timestamp );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".COMMENT", $r->comment );

    return $res;
}

function to_generic_request__OpenJobStatus( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".JOB_ID", $r->job_id );
    $res .= "&" . to_generic_request__OpenJobStatus_state_e( $prefix . ".STATE", $r->state );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".CURRENT_TRY", $r->current_try );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".TIMESTAMP", $r->timestamp );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".NEXT_EXEC_TIME", $r->next_exec_time );

    return $res;
}

function to_generic_request__TemplateInfo( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".ID", $r->id );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".CATEGORY_ID", $r->category_id );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".NAME", $r->name );
    $res .= "&" . \lang_tools\to_generic_request__lang_e( $prefix . ".LANG", $r->lang );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".LOCALIZED_NAME", $r->localized_name );
    $res .= "&" . \basic_parser\to_generic_request__vector( $prefix . ".PLACEHOLDERS", $r->placeholders, '\basic_parser\to_generic_request__string' ); // Array

    return $res;
}

function to_generic_request__CancellationFailureReason( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".JOB_ID", $r->job_id );
    $res .= "&" . \generic_protocol\to_generic_request__ErrorResponse_type_e( $prefix . ".TYPE", $r->type );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".DESCR", $r->descr );

    return $res;
}

function to_generic_request__Action( $prefix, & $r )
{
    $res = "";
    $res .= "&" . to_generic_request__action_type_e( $prefix . ".TYPE", $r->type );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".MSG_TEMPL_ID", $r->msg_templ_id );

    return $res;
}

function to_generic_request__ContactPhone( $prefix, & $r )
{
    $res = "";
    $res .= "&" . to_generic_request__ContactPhone_type_e( $prefix . ".TYPE", $r->type );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".PHONE_NUMBER", $r->phone_number );

    return $res;
}

function to_generic_request__ContactPhoneWithId( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".CONTACT_PHONE_ID", $r->contact_phone_id );
    $res .= "&" . to_generic_request__ContactPhone( $prefix . ".CONTACT_PHONE", $r->contact_phone );

    return $res;
}

function to_generic_request__Contact( $prefix, & $r )
{
    $res = "";
    $res .= "&" . to_generic_request__gender_e( $prefix . ".GENDER", $r->gender );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".NAME", $r->name );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".FIRST_NAME", $r->first_name );
    $res .= "&" . \basic_objects\to_generic_request__Date( $prefix . ".BIRTHDAY", $r->birthday );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".NOTICE", $r->notice );

    return $res;
}

function to_generic_request__ExtendedContactInfo( $prefix, & $r )
{
    $res = "";
    $res .= "&" . to_generic_request__voice_e( $prefix . ".VOICE", $r->voice );
    $res .= "&" . \lang_tools\to_generic_request__lang_e( $prefix . ".LANG", $r->lang );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".MAX_TRIES", $r->max_tries );
    $res .= "&" . \basic_parser\to_generic_request__bool( $prefix . ".REDIAL_IF_NO_FEEDBACK", $r->redial_if_no_feedback );
    $res .= "&" . \basic_objects\to_generic_request__TimeWindow( $prefix . ".TIME_WINDOW", $r->time_window );
    $res .= "&" . \basic_objects\to_generic_request__Weekdays( $prefix . ".WEEKDAYS", $r->weekdays );

    return $res;
}

function to_generic_request__ReminderAction( $prefix, & $r )
{
    $res = "";
    $res .= "&" . to_generic_request__ReminderAction_type_e( $prefix . ".TYPE", $r->type );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".MSG_TEMPL_ID", $r->msg_templ_id );

    return $res;
}

function to_generic_request__ReminderOptions( $prefix, & $r )
{
    $res = "";
    $res .= "&" . to_generic_request__voice_e( $prefix . ".VOICE", $r->voice );
    $res .= "&" . \lang_tools\to_generic_request__lang_e( $prefix . ".LANG", $r->lang );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".MAX_TRIES", $r->max_tries );
    $res .= "&" . \basic_parser\to_generic_request__bool( $prefix . ".REDIAL_IF_NO_FEEDBACK", $r->redial_if_no_feedback );
    $res .= "&" . \basic_objects\to_generic_request__TimeWindow( $prefix . ".TIME_WINDOW", $r->time_window );
    $res .= "&" . \basic_objects\to_generic_request__Weekdays( $prefix . ".WEEKDAYS", $r->weekdays );

    return $res;
}

function to_generic_request__Reminder( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".MSG_TEMPL_ID", $r->msg_templ_id );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".FEEDBACK_TEMPL_ID", $r->feedback_templ_id );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".EFFECTIVE_TIME", $r->effective_time );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".REMIND_PERIOD", $r->remind_period );
    $res .= "&" . \basic_parser\to_generic_request__map( $prefix . ".PARAMS", $r->params, '\basic_parser\to_generic_request__string', '\basic_parser\to_generic_request__string' ); // Map
    $res .= "&" . \basic_parser\to_generic_request__map( $prefix . ".ACTIONS", $r->actions, '\dtmf_tools\to_generic_request__tone_e', '\persek_protocol\to_generic_request__ReminderAction' ); // Map
    $res .= "&" . to_generic_request__ReminderOptions( $prefix . ".OPTIONS", $r->options );

    return $res;
}

// base messages

function to_generic_request__Request( & $r )
{
    $res = "";

    return $res;
}

function to_generic_request__BackwardMessage( & $r )
{
    $res = "";

    return $res;
}

// messages

function to_generic_request__GetJobInfoRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetJobInfoRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );
    $res .= "&" . \basic_parser\to_generic_request__vector( "JOB_IDS", $r->job_ids, '\basic_parser\to_generic_request__int' ); // Array

    return $res;
}

function to_generic_request__GetJobInfoResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetJobInfoResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__vector( "JOBS", $r->jobs, '\persek_protocol\to_generic_request__JobInfo' ); // Array

    return $res;
}

function to_generic_request__GetJobStatRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetJobStatRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );
    $res .= "&" . \basic_parser\to_generic_request__vector( "JOB_IDS", $r->job_ids, '\basic_parser\to_generic_request__int' ); // Array

    return $res;
}

function to_generic_request__GetJobStatResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetJobStatResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__vector( "OPEN_JOBS", $r->open_jobs, '\persek_protocol\to_generic_request__OpenJobStatus' ); // Array
    $res .= "&" . \basic_parser\to_generic_request__vector( "CLOSED_JOBS", $r->closed_jobs, '\persek_protocol\to_generic_request__ClosedJobStatus' ); // Array

    return $res;
}

function to_generic_request__FindJobRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/FindJobRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );
    $res .= "&" . to_generic_request__FindJobRequest_status_e( "STATUS", $r->status );
    $res .= "&" . \basic_parser\to_generic_request__string( "CONTACT_REGEX", $r->contact_regex );
    $res .= "&" . \basic_objects\to_generic_request__TimeRange( "CREATION_TIME_RANGE", $r->creation_time_range );
    $res .= "&" . \basic_objects\to_generic_request__TimeRange( "EXEC_TIME_RANGE", $r->exec_time_range );
    $res .= "&" . \basic_objects\to_generic_request__TimeRange( "UPDATE_TIME_RANGE", $r->update_time_range );
    $res .= "&" . \basic_parser\to_generic_request__int( "MAX_RESULTS", $r->max_results );
    $res .= "&" . \basic_parser\to_generic_request__int( "OFFSET", $r->offset );

    return $res;
}

function to_generic_request__FindJobResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/FindJobResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "TOTAL_SIZE", $r->total_size );
    $res .= "&" . \basic_parser\to_generic_request__vector( "JOB_IDS", $r->job_ids, '\basic_parser\to_generic_request__int' ); // Array

    return $res;
}

function to_generic_request__FindTemplatesRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/FindTemplatesRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );
    $res .= "&" . \basic_parser\to_generic_request__int( "CATEGORY_ID", $r->category_id );
    $res .= "&" . \basic_parser\to_generic_request__string( "NAME_REGEX", $r->name_regex );
    $res .= "&" . \lang_tools\to_generic_request__lang_e( "LANG", $r->lang );

    return $res;
}

function to_generic_request__FindTemplatesResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/FindTemplatesResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__vector( "TEMPLATES", $r->templates, '\persek_protocol\to_generic_request__TemplateInfo' ); // Array

    return $res;
}

function to_generic_request__CancelJobRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/CancelJobRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "JOB_ID", $r->job_id );

    return $res;
}

function to_generic_request__CancelJobResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/CancelJobResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__CancelJobsRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/CancelJobsRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__vector( "JOB_IDS", $r->job_ids, '\basic_parser\to_generic_request__int' ); // Array

    return $res;
}

function to_generic_request__CancelJobsResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/CancelJobsResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__vector( "CANCELLED_JOB_IDS", $r->cancelled_job_ids, '\basic_parser\to_generic_request__int' ); // Array
    $res .= "&" . \basic_parser\to_generic_request__vector( "FAILED_JOBS", $r->failed_jobs, '\persek_protocol\to_generic_request__CancellationFailureReason' ); // Array

    return $res;
}

function to_generic_request__SayRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/SayRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );
    $res .= "&" . \basic_parser\to_generic_request__string( "CONTACT_ID", $r->contact_id );
    $res .= "&" . \basic_parser\to_generic_request__int( "MSG_TEMPL_ID", $r->msg_templ_id );
    $res .= "&" . \basic_parser\to_generic_request__map( "PARAMS", $r->params, '\basic_parser\to_generic_request__string', '\basic_parser\to_generic_request__string' ); // Map
    $res .= "&" . to_generic_request__JobOptions( "OPTIONS", $r->options );

    return $res;
}

function to_generic_request__SayResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/SayResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "JOB_ID", $r->job_id );

    return $res;
}

function to_generic_request__SayFeedbackRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/SayFeedbackRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );
    $res .= "&" . \basic_parser\to_generic_request__string( "CONTACT_ID", $r->contact_id );
    $res .= "&" . \basic_parser\to_generic_request__int( "MSG_TEMPL_ID", $r->msg_templ_id );
    $res .= "&" . \basic_parser\to_generic_request__int( "FEEDBACK_TEMPL_ID", $r->feedback_templ_id );
    $res .= "&" . \basic_parser\to_generic_request__map( "PARAMS", $r->params, '\basic_parser\to_generic_request__string', '\basic_parser\to_generic_request__string' ); // Map
    $res .= "&" . \basic_parser\to_generic_request__map( "ACTIONS", $r->actions, '\dtmf_tools\to_generic_request__tone_e', '\persek_protocol\to_generic_request__Action' ); // Map
    $res .= "&" . to_generic_request__JobOptions( "OPTIONS", $r->options );

    return $res;
}

function to_generic_request__SayFeedbackResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/SayFeedbackResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "JOB_ID", $r->job_id );

    return $res;
}

function to_generic_request__AddContactPhoneRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/AddContactPhoneRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_ID", $r->contact_id );
    $res .= "&" . to_generic_request__ContactPhone( "CONTACT_PHONE", $r->contact_phone );

    return $res;
}

function to_generic_request__AddContactPhoneResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/AddContactPhoneResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_PHONE_ID", $r->contact_phone_id );

    return $res;
}

function to_generic_request__ModifyContactPhoneRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/ModifyContactPhoneRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_PHONE_ID", $r->contact_phone_id );
    $res .= "&" . to_generic_request__ContactPhone( "CONTACT_PHONE", $r->contact_phone );

    return $res;
}

function to_generic_request__ModifyContactPhoneResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/ModifyContactPhoneResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__DeleteContactPhoneRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/DeleteContactPhoneRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_PHONE_ID", $r->contact_phone_id );

    return $res;
}

function to_generic_request__DeleteContactPhoneResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/DeleteContactPhoneResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__GetContactPhoneRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetContactPhoneRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_PHONE_ID", $r->contact_phone_id );

    return $res;
}

function to_generic_request__GetContactPhoneResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetContactPhoneResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_ID", $r->contact_id );
    $res .= "&" . to_generic_request__ContactPhone( "CONTACT_PHONE", $r->contact_phone );

    return $res;
}

function to_generic_request__AddContactRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/AddContactRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );
    $res .= "&" . to_generic_request__Contact( "CONTACT", $r->contact );

    return $res;
}

function to_generic_request__AddContactResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/AddContactResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_ID", $r->contact_id );

    return $res;
}

function to_generic_request__ModifyContactRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/ModifyContactRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_ID", $r->contact_id );
    $res .= "&" . to_generic_request__Contact( "CONTACT", $r->contact );

    return $res;
}

function to_generic_request__ModifyContactResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/ModifyContactResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__DeleteContactRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/DeleteContactRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_ID", $r->contact_id );

    return $res;
}

function to_generic_request__DeleteContactResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/DeleteContactResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__GetContactRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetContactRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_ID", $r->contact_id );

    return $res;
}

function to_generic_request__GetContactResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetContactResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . to_generic_request__Contact( "CONTACT", $r->contact );
    $res .= "&" . \basic_parser\to_generic_request__vector( "CONTACT_PHONE_IDS", $r->contact_phone_ids, '\basic_parser\to_generic_request__int' ); // Array

    return $res;
}

function to_generic_request__GetContactWithPhonesRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetContactWithPhonesRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_ID", $r->contact_id );

    return $res;
}

function to_generic_request__GetContactWithPhonesResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetContactWithPhonesResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . to_generic_request__Contact( "CONTACT", $r->contact );
    $res .= "&" . \basic_parser\to_generic_request__vector( "CONTACT_PHONES", $r->contact_phones, '\persek_protocol\to_generic_request__ContactPhoneWithId' ); // Array

    return $res;
}

function to_generic_request__GetContactExtRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetContactExtRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_ID", $r->contact_id );

    return $res;
}

function to_generic_request__GetContactExtResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetContactExtResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . to_generic_request__Contact( "CONTACT", $r->contact );
    $res .= "&" . \basic_parser\to_generic_request__vector( "CONTACT_PHONES", $r->contact_phones, '\persek_protocol\to_generic_request__ContactPhoneWithId' ); // Array
    $res .= "&" . to_generic_request__ExtendedContactInfo( "EXTENDED_INFO", $r->extended_info );

    return $res;
}

function to_generic_request__GetExtendedContactInfoRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetExtendedContactInfoRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_ID", $r->contact_id );

    return $res;
}

function to_generic_request__GetExtendedContactInfoResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetExtendedContactInfoResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . to_generic_request__ExtendedContactInfo( "EXTENDED_INFO", $r->extended_info );

    return $res;
}

function to_generic_request__SetExtendedContactInfoRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/SetExtendedContactInfoRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_ID", $r->contact_id );
    $res .= "&" . to_generic_request__ExtendedContactInfo( "EXTENDED_INFO", $r->extended_info );

    return $res;
}

function to_generic_request__SetExtendedContactInfoResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/SetExtendedContactInfoResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__AddReminderRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/AddReminderRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_PHONE_ID", $r->contact_phone_id );
    $res .= "&" . to_generic_request__Reminder( "REMINDER", $r->reminder );

    return $res;
}

function to_generic_request__AddReminderResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/AddReminderResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "JOB_ID", $r->job_id );

    return $res;
}

function to_generic_request__ModifyReminderRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/ModifyReminderRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "JOB_ID", $r->job_id );
    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_PHONE_ID", $r->contact_phone_id );
    $res .= "&" . to_generic_request__Reminder( "REMINDER", $r->reminder );

    return $res;
}

function to_generic_request__ModifyReminderResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/ModifyReminderResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__GetReminderRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetReminderRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "JOB_ID", $r->job_id );

    return $res;
}

function to_generic_request__GetReminderResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetReminderResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_ID", $r->contact_id );
    $res .= "&" . \basic_parser\to_generic_request__int( "CONTACT_PHONE_ID", $r->contact_phone_id );
    $res .= "&" . \basic_parser\to_generic_request__string( "CONTACT_PHONE", $r->contact_phone );
    $res .= "&" . to_generic_request__Reminder( "REMINDER", $r->reminder );

    return $res;
}

function to_generic_request__GetReminderStatusRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "persek/GetReminderStatusRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );
    $res .= "&" . \basic_parser\to_generic_request__string( "SEARCH_FILTER", $r->search_filter );
    $res .= "&" . \basic_objects\to_generic_request__TimeRange( "EFFECTIVE_DATE_TIME_RANGE", $r->effective_date_time_range );
    $res .= "&" . \basic_parser\to_generic_request__int( "PAGE_SIZE", $r->page_size );
    $res .= "&" . \basic_parser\to_generic_request__int( "PAGE_NUMBER", $r->page_number );

    return $res;
}

// generic

function to_generic_request( $obj )
{
    $handler_map = array(
        // messages
        'persek_protocol\GetJobInfoRequest'         => 'to_generic_request__GetJobInfoRequest',
        'persek_protocol\GetJobInfoResponse'         => 'to_generic_request__GetJobInfoResponse',
        'persek_protocol\GetJobStatRequest'         => 'to_generic_request__GetJobStatRequest',
        'persek_protocol\GetJobStatResponse'         => 'to_generic_request__GetJobStatResponse',
        'persek_protocol\FindJobRequest'         => 'to_generic_request__FindJobRequest',
        'persek_protocol\FindJobResponse'         => 'to_generic_request__FindJobResponse',
        'persek_protocol\FindTemplatesRequest'         => 'to_generic_request__FindTemplatesRequest',
        'persek_protocol\FindTemplatesResponse'         => 'to_generic_request__FindTemplatesResponse',
        'persek_protocol\CancelJobRequest'         => 'to_generic_request__CancelJobRequest',
        'persek_protocol\CancelJobResponse'         => 'to_generic_request__CancelJobResponse',
        'persek_protocol\CancelJobsRequest'         => 'to_generic_request__CancelJobsRequest',
        'persek_protocol\CancelJobsResponse'         => 'to_generic_request__CancelJobsResponse',
        'persek_protocol\SayRequest'         => 'to_generic_request__SayRequest',
        'persek_protocol\SayResponse'         => 'to_generic_request__SayResponse',
        'persek_protocol\SayFeedbackRequest'         => 'to_generic_request__SayFeedbackRequest',
        'persek_protocol\SayFeedbackResponse'         => 'to_generic_request__SayFeedbackResponse',
        'persek_protocol\AddContactPhoneRequest'         => 'to_generic_request__AddContactPhoneRequest',
        'persek_protocol\AddContactPhoneResponse'         => 'to_generic_request__AddContactPhoneResponse',
        'persek_protocol\ModifyContactPhoneRequest'         => 'to_generic_request__ModifyContactPhoneRequest',
        'persek_protocol\ModifyContactPhoneResponse'         => 'to_generic_request__ModifyContactPhoneResponse',
        'persek_protocol\DeleteContactPhoneRequest'         => 'to_generic_request__DeleteContactPhoneRequest',
        'persek_protocol\DeleteContactPhoneResponse'         => 'to_generic_request__DeleteContactPhoneResponse',
        'persek_protocol\GetContactPhoneRequest'         => 'to_generic_request__GetContactPhoneRequest',
        'persek_protocol\GetContactPhoneResponse'         => 'to_generic_request__GetContactPhoneResponse',
        'persek_protocol\AddContactRequest'         => 'to_generic_request__AddContactRequest',
        'persek_protocol\AddContactResponse'         => 'to_generic_request__AddContactResponse',
        'persek_protocol\ModifyContactRequest'         => 'to_generic_request__ModifyContactRequest',
        'persek_protocol\ModifyContactResponse'         => 'to_generic_request__ModifyContactResponse',
        'persek_protocol\DeleteContactRequest'         => 'to_generic_request__DeleteContactRequest',
        'persek_protocol\DeleteContactResponse'         => 'to_generic_request__DeleteContactResponse',
        'persek_protocol\GetContactRequest'         => 'to_generic_request__GetContactRequest',
        'persek_protocol\GetContactResponse'         => 'to_generic_request__GetContactResponse',
        'persek_protocol\GetContactWithPhonesRequest'         => 'to_generic_request__GetContactWithPhonesRequest',
        'persek_protocol\GetContactWithPhonesResponse'         => 'to_generic_request__GetContactWithPhonesResponse',
        'persek_protocol\GetContactExtRequest'         => 'to_generic_request__GetContactExtRequest',
        'persek_protocol\GetContactExtResponse'         => 'to_generic_request__GetContactExtResponse',
        'persek_protocol\GetExtendedContactInfoRequest'         => 'to_generic_request__GetExtendedContactInfoRequest',
        'persek_protocol\GetExtendedContactInfoResponse'         => 'to_generic_request__GetExtendedContactInfoResponse',
        'persek_protocol\SetExtendedContactInfoRequest'         => 'to_generic_request__SetExtendedContactInfoRequest',
        'persek_protocol\SetExtendedContactInfoResponse'         => 'to_generic_request__SetExtendedContactInfoResponse',
        'persek_protocol\AddReminderRequest'         => 'to_generic_request__AddReminderRequest',
        'persek_protocol\AddReminderResponse'         => 'to_generic_request__AddReminderResponse',
        'persek_protocol\ModifyReminderRequest'         => 'to_generic_request__ModifyReminderRequest',
        'persek_protocol\ModifyReminderResponse'         => 'to_generic_request__ModifyReminderResponse',
        'persek_protocol\GetReminderRequest'         => 'to_generic_request__GetReminderRequest',
        'persek_protocol\GetReminderResponse'         => 'to_generic_request__GetReminderResponse',
        'persek_protocol\GetReminderStatusRequest'         => 'to_generic_request__GetReminderStatusRequest',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\persek_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \generic_protocol\to_generic_request( $obj );
}

# namespace_end persek_protocol


?>
