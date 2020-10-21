<?php

namespace persek_protocol;


// base include
require_once __DIR__.'/../generic_protocol/str_helper.php';
// includes
require_once __DIR__.'/../basic_objects/str_helper.php';
require_once __DIR__.'/../dtmf_tools_protocol/str_helper.php';
require_once __DIR__.'/../lang_tools_protocol/str_helper.php';
require_once __DIR__.'/../basic_parser/str_helper.php';

// enums

function to_string__voice_e( $r )
{
    $map = array
    (
        voice_e__UNDEF => 'UNDEF',
        voice_e__MALE_A => 'MALE_A',
        voice_e__FEMALE_A => 'FEMALE_A',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

function to_string__urgency_e( $r )
{
    $map = array
    (
        urgency_e__UNDEF => 'UNDEF',
        urgency_e__IMMEDIATE => 'IMMEDIATE',
        urgency_e__TIMED => 'TIMED',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

function to_string__JobInfo_type_e( $r )
{
    $map = array
    (
        JobInfo_type_e__UNDEF => 'UNDEF',
        JobInfo_type_e__SAY => 'SAY',
        JobInfo_type_e__SAY_FEEDBACK => 'SAY_FEEDBACK',
        JobInfo_type_e__FSM => 'FSM',
        JobInfo_type_e__REMINDER => 'REMINDER',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

function to_string__exit_status_e( $r )
{
    $map = array
    (
        exit_status_e__DONE => 'DONE',
        exit_status_e__CANCELLED => 'CANCELLED',
        exit_status_e__FAILED => 'FAILED',
        exit_status_e__REFUSED_BY_RECIPIENT => 'REFUSED_BY_RECIPIENT',
        exit_status_e__ABORTED_BY_RECIPIENT => 'ABORTED_BY_RECIPIENT',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

function to_string__OpenJobStatus_state_e( $r )
{
    $map = array
    (
        OpenJobStatus_state_e__IDLE => 'IDLE',
        OpenJobStatus_state_e__WAITING_PROC_STARTED => 'WAITING_PROC_STARTED',
        OpenJobStatus_state_e__ACTIVE => 'ACTIVE',
        OpenJobStatus_state_e__WRONG_ACTIVE => 'WRONG_ACTIVE',
        OpenJobStatus_state_e__CANCELLED_IN_A => 'CANCELLED_IN_A',
        OpenJobStatus_state_e__CANCELLED_IN_WPS => 'CANCELLED_IN_WPS',
        OpenJobStatus_state_e__COMPLETED => 'COMPLETED',
        OpenJobStatus_state_e__WAITING_REDIAL_TIMER => 'WAITING_REDIAL_TIMER',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

function to_string__FindJobRequest_status_e( $r )
{
    $map = array
    (
        FindJobRequest_status_e__ANY => 'ANY',
        FindJobRequest_status_e__OPEN => 'OPEN',
        FindJobRequest_status_e__CLOSED => 'CLOSED',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

function to_string__action_type_e( $r )
{
    $map = array
    (
        action_type_e__NONE => 'NONE',
        action_type_e__REPEAT => 'REPEAT',
        action_type_e__DROP => 'DROP',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

function to_string__ContactPhone_type_e( $r )
{
    $map = array
    (
        ContactPhone_type_e__DFLT => 'DFLT',
        ContactPhone_type_e__LANDLINE => 'LANDLINE',
        ContactPhone_type_e__MOBILE => 'MOBILE',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

function to_string__gender_e( $r )
{
    $map = array
    (
        gender_e__UNDEF => 'UNDEF',
        gender_e__MALE => 'MALE',
        gender_e__FEMALE => 'FEMALE',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

function to_string__ReminderAction_type_e( $r )
{
    $map = array
    (
        ReminderAction_type_e__NONE => 'NONE',
        ReminderAction_type_e__REPEAT => 'REPEAT',
        ReminderAction_type_e__DROP_FEEDBACK => 'DROP_FEEDBACK',
        ReminderAction_type_e__DROP_SNOOZE => 'DROP_SNOOZE',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

// objects

function to_string__JobOptions( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " voice=" . to_string__voice_e( $r->voice );
    $res .= " urgency=" . to_string__urgency_e( $r->urgency );
    $res .= " lang=" . \lang_tools_protocol\to_string__lang_e( $r->lang );
    $res .= " exec_time=" . \basic_parser\to_string__int( $r->exec_time );
    $res .= " max_tries=" . \basic_parser\to_string__int( $r->max_tries );
    $res .= " redial_if_no_feedback=" . \basic_parser\to_string__bool( $r->redial_if_no_feedback );
    $res .= " time_window=" . \basic_objects\to_string__TimeWindow( $r->time_window );
    $res .= " weekdays_mask=" . \basic_objects\to_string__Weekdays( $r->weekdays_mask );

    $res .= ")";

    return $res;
}

function to_string__JobInfo( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " job_id=" . \basic_parser\to_string__int( $r->job_id );
    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " type=" . to_string__JobInfo_type_e( $r->type );
    $res .= " contact=" . \basic_parser\to_string__string( $r->contact );
    $res .= " creation_time=" . \basic_parser\to_string__int( $r->creation_time );
    $res .= " options=" . to_string__JobOptions( $r->options );

    $res .= ")";

    return $res;
}

function to_string__ClosedJobStatus( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " job_id=" . \basic_parser\to_string__int( $r->job_id );
    $res .= " exit_code=" . to_string__exit_status_e( $r->exit_code );
    $res .= " feedback=" . \basic_parser\to_string__vector( $r->feedback, '\basic_parser\to_string__int' ); // Array
    $res .= " num_tries=" . \basic_parser\to_string__int( $r->num_tries );
    $res .= " timestamp=" . \basic_parser\to_string__int( $r->timestamp );
    $res .= " comment=" . \basic_parser\to_string__string( $r->comment );

    $res .= ")";

    return $res;
}

function to_string__OpenJobStatus( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " job_id=" . \basic_parser\to_string__int( $r->job_id );
    $res .= " state=" . to_string__OpenJobStatus_state_e( $r->state );
    $res .= " current_try=" . \basic_parser\to_string__int( $r->current_try );
    $res .= " timestamp=" . \basic_parser\to_string__int( $r->timestamp );
    $res .= " next_exec_time=" . \basic_parser\to_string__int( $r->next_exec_time );

    $res .= ")";

    return $res;
}

function to_string__TemplateInfo( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " id=" . \basic_parser\to_string__int( $r->id );
    $res .= " category_id=" . \basic_parser\to_string__int( $r->category_id );
    $res .= " name=" . \basic_parser\to_string__string( $r->name );
    $res .= " lang=" . \lang_tools_protocol\to_string__lang_e( $r->lang );
    $res .= " localized_name=" . \basic_parser\to_string__string( $r->localized_name );
    $res .= " placeholders=" . \basic_parser\to_string__vector( $r->placeholders, '\basic_parser\to_string__string' ); // Array

    $res .= ")";

    return $res;
}

function to_string__CancellationFailureReason( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " job_id=" . \basic_parser\to_string__int( $r->job_id );
    $res .= " type=" . \generic_protocol\to_string__ErrorResponse_type_e( $r->type );
    $res .= " descr=" . \basic_parser\to_string__string( $r->descr );

    $res .= ")";

    return $res;
}

function to_string__Action( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " type=" . to_string__action_type_e( $r->type );
    $res .= " msg_templ_id=" . \basic_parser\to_string__int( $r->msg_templ_id );

    $res .= ")";

    return $res;
}

function to_string__ContactPhone( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " type=" . to_string__ContactPhone_type_e( $r->type );
    $res .= " phone_number=" . \basic_parser\to_string__string( $r->phone_number );

    $res .= ")";

    return $res;
}

function to_string__ContactPhoneWithId( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " contact_phone_id=" . \basic_parser\to_string__int( $r->contact_phone_id );
    $res .= " contact_phone=" . to_string__ContactPhone( $r->contact_phone );

    $res .= ")";

    return $res;
}

function to_string__Contact( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " gender=" . to_string__gender_e( $r->gender );
    $res .= " name=" . \basic_parser\to_string__string( $r->name );
    $res .= " first_name=" . \basic_parser\to_string__string( $r->first_name );
    $res .= " birthday=" . \basic_objects\to_string__Date( $r->birthday );
    $res .= " notice=" . \basic_parser\to_string__string( $r->notice );

    $res .= ")";

    return $res;
}

function to_string__ExtendedContactInfo( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " voice=" . to_string__voice_e( $r->voice );
    $res .= " lang=" . \lang_tools_protocol\to_string__lang_e( $r->lang );
    $res .= " max_tries=" . \basic_parser\to_string__int( $r->max_tries );
    $res .= " redial_if_no_feedback=" . \basic_parser\to_string__bool( $r->redial_if_no_feedback );
    $res .= " time_window=" . \basic_objects\to_string__TimeWindow( $r->time_window );
    $res .= " weekdays=" . \basic_objects\to_string__Weekdays( $r->weekdays );

    $res .= ")";

    return $res;
}

function to_string__ReminderAction( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " type=" . to_string__ReminderAction_type_e( $r->type );
    $res .= " msg_templ_id=" . \basic_parser\to_string__int( $r->msg_templ_id );

    $res .= ")";

    return $res;
}

function to_string__ReminderOptions( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " voice=" . to_string__voice_e( $r->voice );
    $res .= " lang=" . \lang_tools_protocol\to_string__lang_e( $r->lang );
    $res .= " max_tries=" . \basic_parser\to_string__int( $r->max_tries );
    $res .= " redial_if_no_feedback=" . \basic_parser\to_string__bool( $r->redial_if_no_feedback );
    $res .= " time_window=" . \basic_objects\to_string__TimeWindow( $r->time_window );
    $res .= " weekdays=" . \basic_objects\to_string__Weekdays( $r->weekdays );

    $res .= ")";

    return $res;
}

function to_string__Reminder( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " msg_templ_id=" . \basic_parser\to_string__int( $r->msg_templ_id );
    $res .= " feedback_templ_id=" . \basic_parser\to_string__int( $r->feedback_templ_id );
    $res .= " effective_time=" . \basic_parser\to_string__int( $r->effective_time );
    $res .= " remind_period=" . \basic_parser\to_string__int( $r->remind_period );
    $res .= " params=" . \basic_parser\to_string__map( $r->params, '\basic_parser\to_string__string', '\basic_parser\to_string__string' ); // Map
    $res .= " actions=" . \basic_parser\to_string__map( $r->actions, '\dtmf_tools_protocol\to_string__tone_e', '\persek_protocol\to_string__ReminderAction' ); // Map
    $res .= " options=" . to_string__ReminderOptions( $r->options );

    $res .= ")";

    return $res;
}

// base messages

function to_string__Request( & $r )
{
    $res = "";

    $res .= "(";

    // base class
    $res .= \generic_protocol\to_string__Request( $r );


    $res .= ")";

    return $res;
}

function to_string__BackwardMessage( & $r )
{
    $res = "";

    $res .= "(";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );


    $res .= ")";

    return $res;
}

// messages

function to_string__GetJobInfoRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " job_ids=" . \basic_parser\to_string__vector( $r->job_ids, '\basic_parser\to_string__int' ); // Array

    return $res;
}

function to_string__GetJobInfoResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " jobs=" . \basic_parser\to_string__vector( $r->jobs, '\persek_protocol\to_string__JobInfo' ); // Array

    return $res;
}

function to_string__GetJobStatRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " job_ids=" . \basic_parser\to_string__vector( $r->job_ids, '\basic_parser\to_string__int' ); // Array

    return $res;
}

function to_string__GetJobStatResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " open_jobs=" . \basic_parser\to_string__vector( $r->open_jobs, '\persek_protocol\to_string__OpenJobStatus' ); // Array
    $res .= " closed_jobs=" . \basic_parser\to_string__vector( $r->closed_jobs, '\persek_protocol\to_string__ClosedJobStatus' ); // Array

    return $res;
}

function to_string__FindJobRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " status=" . to_string__FindJobRequest_status_e( $r->status );
    $res .= " contact_regex=" . \basic_parser\to_string__string( $r->contact_regex );
    $res .= " creation_time_range=" . \basic_objects\to_string__TimeRange( $r->creation_time_range );
    $res .= " exec_time_range=" . \basic_objects\to_string__TimeRange( $r->exec_time_range );
    $res .= " update_time_range=" . \basic_objects\to_string__TimeRange( $r->update_time_range );
    $res .= " max_results=" . \basic_parser\to_string__int( $r->max_results );
    $res .= " offset=" . \basic_parser\to_string__int( $r->offset );

    return $res;
}

function to_string__FindJobResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " total_size=" . \basic_parser\to_string__int( $r->total_size );
    $res .= " job_ids=" . \basic_parser\to_string__vector( $r->job_ids, '\basic_parser\to_string__int' ); // Array

    return $res;
}

function to_string__FindTemplatesRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " category_id=" . \basic_parser\to_string__int( $r->category_id );
    $res .= " name_regex=" . \basic_parser\to_string__string( $r->name_regex );
    $res .= " lang=" . \lang_tools_protocol\to_string__lang_e( $r->lang );

    return $res;
}

function to_string__FindTemplatesResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " templates=" . \basic_parser\to_string__vector( $r->templates, '\persek_protocol\to_string__TemplateInfo' ); // Array

    return $res;
}

function to_string__CancelJobRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " job_id=" . \basic_parser\to_string__int( $r->job_id );

    return $res;
}

function to_string__CancelJobResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );


    return $res;
}

function to_string__CancelJobsRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " job_ids=" . \basic_parser\to_string__vector( $r->job_ids, '\basic_parser\to_string__int' ); // Array

    return $res;
}

function to_string__CancelJobsResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " cancelled_job_ids=" . \basic_parser\to_string__vector( $r->cancelled_job_ids, '\basic_parser\to_string__int' ); // Array
    $res .= " failed_jobs=" . \basic_parser\to_string__vector( $r->failed_jobs, '\persek_protocol\to_string__CancellationFailureReason' ); // Array

    return $res;
}

function to_string__SayRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " contact_id=" . \basic_parser\to_string__string( $r->contact_id );
    $res .= " msg_templ_id=" . \basic_parser\to_string__int( $r->msg_templ_id );
    $res .= " params=" . \basic_parser\to_string__map( $r->params, '\basic_parser\to_string__string', '\basic_parser\to_string__string' ); // Map
    $res .= " options=" . to_string__JobOptions( $r->options );

    return $res;
}

function to_string__SayResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " job_id=" . \basic_parser\to_string__int( $r->job_id );

    return $res;
}

function to_string__SayFeedbackRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " contact_id=" . \basic_parser\to_string__string( $r->contact_id );
    $res .= " msg_templ_id=" . \basic_parser\to_string__int( $r->msg_templ_id );
    $res .= " feedback_templ_id=" . \basic_parser\to_string__int( $r->feedback_templ_id );
    $res .= " params=" . \basic_parser\to_string__map( $r->params, '\basic_parser\to_string__string', '\basic_parser\to_string__string' ); // Map
    $res .= " actions=" . \basic_parser\to_string__map( $r->actions, '\dtmf_tools_protocol\to_string__tone_e', '\persek_protocol\to_string__Action' ); // Map
    $res .= " options=" . to_string__JobOptions( $r->options );

    return $res;
}

function to_string__SayFeedbackResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " job_id=" . \basic_parser\to_string__int( $r->job_id );

    return $res;
}

function to_string__AddContactPhoneRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " contact_id=" . \basic_parser\to_string__int( $r->contact_id );
    $res .= " contact_phone=" . to_string__ContactPhone( $r->contact_phone );

    return $res;
}

function to_string__AddContactPhoneResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " contact_phone_id=" . \basic_parser\to_string__int( $r->contact_phone_id );

    return $res;
}

function to_string__ModifyContactPhoneRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " contact_phone_id=" . \basic_parser\to_string__int( $r->contact_phone_id );
    $res .= " contact_phone=" . to_string__ContactPhone( $r->contact_phone );

    return $res;
}

function to_string__ModifyContactPhoneResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );


    return $res;
}

function to_string__DeleteContactPhoneRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " contact_phone_id=" . \basic_parser\to_string__int( $r->contact_phone_id );

    return $res;
}

function to_string__DeleteContactPhoneResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );


    return $res;
}

function to_string__GetContactPhoneRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " contact_phone_id=" . \basic_parser\to_string__int( $r->contact_phone_id );

    return $res;
}

function to_string__GetContactPhoneResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " contact_id=" . \basic_parser\to_string__int( $r->contact_id );
    $res .= " contact_phone=" . to_string__ContactPhone( $r->contact_phone );

    return $res;
}

function to_string__AddContactRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " contact=" . to_string__Contact( $r->contact );

    return $res;
}

function to_string__AddContactResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " contact_id=" . \basic_parser\to_string__int( $r->contact_id );

    return $res;
}

function to_string__ModifyContactRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " contact_id=" . \basic_parser\to_string__int( $r->contact_id );
    $res .= " contact=" . to_string__Contact( $r->contact );

    return $res;
}

function to_string__ModifyContactResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );


    return $res;
}

function to_string__DeleteContactRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " contact_id=" . \basic_parser\to_string__int( $r->contact_id );

    return $res;
}

function to_string__DeleteContactResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );


    return $res;
}

function to_string__GetContactRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " contact_id=" . \basic_parser\to_string__int( $r->contact_id );

    return $res;
}

function to_string__GetContactResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " contact=" . to_string__Contact( $r->contact );
    $res .= " contact_phone_ids=" . \basic_parser\to_string__vector( $r->contact_phone_ids, '\basic_parser\to_string__int' ); // Array

    return $res;
}

function to_string__GetContactWithPhonesRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " contact_id=" . \basic_parser\to_string__int( $r->contact_id );

    return $res;
}

function to_string__GetContactWithPhonesResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " contact=" . to_string__Contact( $r->contact );
    $res .= " contact_phones=" . \basic_parser\to_string__vector( $r->contact_phones, '\persek_protocol\to_string__ContactPhoneWithId' ); // Array

    return $res;
}

function to_string__GetContactExtRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " contact_id=" . \basic_parser\to_string__int( $r->contact_id );

    return $res;
}

function to_string__GetContactExtResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " contact=" . to_string__Contact( $r->contact );
    $res .= " contact_phones=" . \basic_parser\to_string__vector( $r->contact_phones, '\persek_protocol\to_string__ContactPhoneWithId' ); // Array
    $res .= " extended_info=" . to_string__ExtendedContactInfo( $r->extended_info );

    return $res;
}

function to_string__GetExtendedContactInfoRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " contact_id=" . \basic_parser\to_string__int( $r->contact_id );

    return $res;
}

function to_string__GetExtendedContactInfoResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " extended_info=" . to_string__ExtendedContactInfo( $r->extended_info );

    return $res;
}

function to_string__SetExtendedContactInfoRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " contact_id=" . \basic_parser\to_string__int( $r->contact_id );
    $res .= " extended_info=" . to_string__ExtendedContactInfo( $r->extended_info );

    return $res;
}

function to_string__SetExtendedContactInfoResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );


    return $res;
}

function to_string__AddReminderRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " contact_phone_id=" . \basic_parser\to_string__int( $r->contact_phone_id );
    $res .= " reminder=" . to_string__Reminder( $r->reminder );

    return $res;
}

function to_string__AddReminderResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " job_id=" . \basic_parser\to_string__int( $r->job_id );

    return $res;
}

function to_string__ModifyReminderRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " job_id=" . \basic_parser\to_string__int( $r->job_id );
    $res .= " contact_phone_id=" . \basic_parser\to_string__int( $r->contact_phone_id );
    $res .= " reminder=" . to_string__Reminder( $r->reminder );

    return $res;
}

function to_string__ModifyReminderResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );


    return $res;
}

function to_string__GetReminderRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " job_id=" . \basic_parser\to_string__int( $r->job_id );

    return $res;
}

function to_string__GetReminderResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " contact_id=" . \basic_parser\to_string__int( $r->contact_id );
    $res .= " contact_phone_id=" . \basic_parser\to_string__int( $r->contact_phone_id );
    $res .= " contact_phone=" . \basic_parser\to_string__string( $r->contact_phone );
    $res .= " reminder=" . to_string__Reminder( $r->reminder );

    return $res;
}

function to_string__GetReminderStatusRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " search_filter=" . \basic_parser\to_string__string( $r->search_filter );
    $res .= " effective_date_time_range=" . \basic_objects\to_string__TimeRange( $r->effective_date_time_range );
    $res .= " page_size=" . \basic_parser\to_string__int( $r->page_size );
    $res .= " page_number=" . \basic_parser\to_string__int( $r->page_number );

    return $res;
}

// generic

function to_string( $obj )
{
    $handler_map = array(
        // objects
        'persek_protocol\JobOptions'         => 'to_string__JobOptions',
        'persek_protocol\JobInfo'         => 'to_string__JobInfo',
        'persek_protocol\ClosedJobStatus'         => 'to_string__ClosedJobStatus',
        'persek_protocol\OpenJobStatus'         => 'to_string__OpenJobStatus',
        'persek_protocol\TemplateInfo'         => 'to_string__TemplateInfo',
        'persek_protocol\CancellationFailureReason'         => 'to_string__CancellationFailureReason',
        'persek_protocol\Action'         => 'to_string__Action',
        'persek_protocol\ContactPhone'         => 'to_string__ContactPhone',
        'persek_protocol\ContactPhoneWithId'         => 'to_string__ContactPhoneWithId',
        'persek_protocol\Contact'         => 'to_string__Contact',
        'persek_protocol\ExtendedContactInfo'         => 'to_string__ExtendedContactInfo',
        'persek_protocol\ReminderAction'         => 'to_string__ReminderAction',
        'persek_protocol\ReminderOptions'         => 'to_string__ReminderOptions',
        'persek_protocol\Reminder'         => 'to_string__Reminder',
        // messages
        'persek_protocol\GetJobInfoRequest'         => 'to_string__GetJobInfoRequest',
        'persek_protocol\GetJobInfoResponse'         => 'to_string__GetJobInfoResponse',
        'persek_protocol\GetJobStatRequest'         => 'to_string__GetJobStatRequest',
        'persek_protocol\GetJobStatResponse'         => 'to_string__GetJobStatResponse',
        'persek_protocol\FindJobRequest'         => 'to_string__FindJobRequest',
        'persek_protocol\FindJobResponse'         => 'to_string__FindJobResponse',
        'persek_protocol\FindTemplatesRequest'         => 'to_string__FindTemplatesRequest',
        'persek_protocol\FindTemplatesResponse'         => 'to_string__FindTemplatesResponse',
        'persek_protocol\CancelJobRequest'         => 'to_string__CancelJobRequest',
        'persek_protocol\CancelJobResponse'         => 'to_string__CancelJobResponse',
        'persek_protocol\CancelJobsRequest'         => 'to_string__CancelJobsRequest',
        'persek_protocol\CancelJobsResponse'         => 'to_string__CancelJobsResponse',
        'persek_protocol\SayRequest'         => 'to_string__SayRequest',
        'persek_protocol\SayResponse'         => 'to_string__SayResponse',
        'persek_protocol\SayFeedbackRequest'         => 'to_string__SayFeedbackRequest',
        'persek_protocol\SayFeedbackResponse'         => 'to_string__SayFeedbackResponse',
        'persek_protocol\AddContactPhoneRequest'         => 'to_string__AddContactPhoneRequest',
        'persek_protocol\AddContactPhoneResponse'         => 'to_string__AddContactPhoneResponse',
        'persek_protocol\ModifyContactPhoneRequest'         => 'to_string__ModifyContactPhoneRequest',
        'persek_protocol\ModifyContactPhoneResponse'         => 'to_string__ModifyContactPhoneResponse',
        'persek_protocol\DeleteContactPhoneRequest'         => 'to_string__DeleteContactPhoneRequest',
        'persek_protocol\DeleteContactPhoneResponse'         => 'to_string__DeleteContactPhoneResponse',
        'persek_protocol\GetContactPhoneRequest'         => 'to_string__GetContactPhoneRequest',
        'persek_protocol\GetContactPhoneResponse'         => 'to_string__GetContactPhoneResponse',
        'persek_protocol\AddContactRequest'         => 'to_string__AddContactRequest',
        'persek_protocol\AddContactResponse'         => 'to_string__AddContactResponse',
        'persek_protocol\ModifyContactRequest'         => 'to_string__ModifyContactRequest',
        'persek_protocol\ModifyContactResponse'         => 'to_string__ModifyContactResponse',
        'persek_protocol\DeleteContactRequest'         => 'to_string__DeleteContactRequest',
        'persek_protocol\DeleteContactResponse'         => 'to_string__DeleteContactResponse',
        'persek_protocol\GetContactRequest'         => 'to_string__GetContactRequest',
        'persek_protocol\GetContactResponse'         => 'to_string__GetContactResponse',
        'persek_protocol\GetContactWithPhonesRequest'         => 'to_string__GetContactWithPhonesRequest',
        'persek_protocol\GetContactWithPhonesResponse'         => 'to_string__GetContactWithPhonesResponse',
        'persek_protocol\GetContactExtRequest'         => 'to_string__GetContactExtRequest',
        'persek_protocol\GetContactExtResponse'         => 'to_string__GetContactExtResponse',
        'persek_protocol\GetExtendedContactInfoRequest'         => 'to_string__GetExtendedContactInfoRequest',
        'persek_protocol\GetExtendedContactInfoResponse'         => 'to_string__GetExtendedContactInfoResponse',
        'persek_protocol\SetExtendedContactInfoRequest'         => 'to_string__SetExtendedContactInfoRequest',
        'persek_protocol\SetExtendedContactInfoResponse'         => 'to_string__SetExtendedContactInfoResponse',
        'persek_protocol\AddReminderRequest'         => 'to_string__AddReminderRequest',
        'persek_protocol\AddReminderResponse'         => 'to_string__AddReminderResponse',
        'persek_protocol\ModifyReminderRequest'         => 'to_string__ModifyReminderRequest',
        'persek_protocol\ModifyReminderResponse'         => 'to_string__ModifyReminderResponse',
        'persek_protocol\GetReminderRequest'         => 'to_string__GetReminderRequest',
        'persek_protocol\GetReminderResponse'         => 'to_string__GetReminderResponse',
        'persek_protocol\GetReminderStatusRequest'         => 'to_string__GetReminderStatusRequest',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\persek_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \generic_protocol\to_string( $obj );
}

// namespace_end persek_protocol


?>
