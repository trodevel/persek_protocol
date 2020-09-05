<?php

namespace persek_protocol;


// includes
require_once __DIR__.'/../generic_protocol/html_helper.php';
require_once __DIR__.'/../basic_objects/html_helper.php';
require_once __DIR__.'/../dtmf_tools_protocol/html_helper.php';
require_once __DIR__.'/../lang_tools_protocol/html_helper.php';
require_once __DIR__.'/../basic_parser/html_helper.php';
require_once 'str_helper.php';

// enums

function to_html_header__voice_e( $r )
{
    return array( 'VOICE_E' );
}

function to_html__voice_e( $r )
{
    return to_string__voice_e( $r ) . " (" . $r . ")";
}

function to_html_header__urgency_e( $r )
{
    return array( 'URGENCY_E' );
}

function to_html__urgency_e( $r )
{
    return to_string__urgency_e( $r ) . " (" . $r . ")";
}

function to_html_header__JobInfo_type_e( $r )
{
    return array( 'JOBINFO_TYPE_E' );
}

function to_html__JobInfo_type_e( $r )
{
    return to_string__JobInfo_type_e( $r ) . " (" . $r . ")";
}

function to_html_header__exit_status_e( $r )
{
    return array( 'EXIT_STATUS_E' );
}

function to_html__exit_status_e( $r )
{
    return to_string__exit_status_e( $r ) . " (" . $r . ")";
}

function to_html_header__OpenJobStatus_state_e( $r )
{
    return array( 'OPENJOBSTATUS_STATE_E' );
}

function to_html__OpenJobStatus_state_e( $r )
{
    return to_string__OpenJobStatus_state_e( $r ) . " (" . $r . ")";
}

function to_html_header__FindJobRequest_status_e( $r )
{
    return array( 'FINDJOBREQUEST_STATUS_E' );
}

function to_html__FindJobRequest_status_e( $r )
{
    return to_string__FindJobRequest_status_e( $r ) . " (" . $r . ")";
}

function to_html_header__action_type_e( $r )
{
    return array( 'ACTION_TYPE_E' );
}

function to_html__action_type_e( $r )
{
    return to_string__action_type_e( $r ) . " (" . $r . ")";
}

function to_html_header__ContactPhone_type_e( $r )
{
    return array( 'CONTACTPHONE_TYPE_E' );
}

function to_html__ContactPhone_type_e( $r )
{
    return to_string__ContactPhone_type_e( $r ) . " (" . $r . ")";
}

function to_html_header__gender_e( $r )
{
    return array( 'GENDER_E' );
}

function to_html__gender_e( $r )
{
    return to_string__gender_e( $r ) . " (" . $r . ")";
}

function to_html_header__ReminderAction_type_e( $r )
{
    return array( 'REMINDERACTION_TYPE_E' );
}

function to_html__ReminderAction_type_e( $r )
{
    return to_string__ReminderAction_type_e( $r ) . " (" . $r . ")";
}

// objects

function to_html__JobOptions( & $r )
{
    $header = array( 'VOICE', 'URGENCY', 'LANG', 'EXEC_TIME', 'MAX_TRIES', 'REDIAL_IF_NO_FEEDBACK', 'TIME_WINDOW', 'WEEKDAYS_MASK' );

    $data = array(
        to_html__voice_e( $r->voice ),
        to_html__urgency_e( $r->urgency ),
        \lang_tools\to_html__lang_e( $r->lang ),
        \basic_parser\to_html__int( $r->exec_time ),
        \basic_parser\to_html__int( $r->max_tries ),
        \basic_parser\to_html__bool( $r->redial_if_no_feedback ),
        \basic_objects\to_html__TimeWindow( $r->time_window ),
        \basic_objects\to_html__Weekdays( $r->weekdays_mask )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__JobInfo( & $r )
{
    $header = array( 'JOB_ID', 'USER_ID', 'TYPE', 'CONTACT', 'CREATION_TIME', 'OPTIONS' );

    $data = array(
        \basic_parser\to_html__int( $r->job_id ),
        \basic_parser\to_html__int( $r->user_id ),
        to_html__JobInfo_type_e( $r->type ),
        \basic_parser\to_html__string( $r->contact ),
        \basic_parser\to_html__int( $r->creation_time ),
        to_html__JobOptions( $r->options )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ClosedJobStatus( & $r )
{
    $header = array( 'JOB_ID', 'EXIT_CODE', 'FEEDBACK', 'NUM_TRIES', 'TIMESTAMP', 'COMMENT' );

    $data = array(
        \basic_parser\to_html__int( $r->job_id ),
        to_html__exit_status_e( $r->exit_code ),
        \basic_parser\to_html__vector( $r->feedback, '\basic_parser\to_html__int' ),
        \basic_parser\to_html__int( $r->num_tries ),
        \basic_parser\to_html__int( $r->timestamp ),
        \basic_parser\to_html__string( $r->comment )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__OpenJobStatus( & $r )
{
    $header = array( 'JOB_ID', 'STATE', 'CURRENT_TRY', 'TIMESTAMP', 'NEXT_EXEC_TIME' );

    $data = array(
        \basic_parser\to_html__int( $r->job_id ),
        to_html__OpenJobStatus_state_e( $r->state ),
        \basic_parser\to_html__int( $r->current_try ),
        \basic_parser\to_html__int( $r->timestamp ),
        \basic_parser\to_html__int( $r->next_exec_time )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__TemplateInfo( & $r )
{
    $header = array( 'ID', 'CATEGORY_ID', 'NAME', 'LANG', 'LOCALIZED_NAME', 'PLACEHOLDERS' );

    $data = array(
        \basic_parser\to_html__int( $r->id ),
        \basic_parser\to_html__int( $r->category_id ),
        \basic_parser\to_html__string( $r->name ),
        \lang_tools\to_html__lang_e( $r->lang ),
        \basic_parser\to_html__string( $r->localized_name ),
        \basic_parser\to_html__vector( $r->placeholders, '\basic_parser\to_html__string' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__CancellationFailureReason( & $r )
{
    $header = array( 'JOB_ID', 'TYPE', 'DESCR' );

    $data = array(
        \basic_parser\to_html__int( $r->job_id ),
        \generic_protocol\to_html__ErrorResponse_type_e( $r->type ),
        \basic_parser\to_html__string( $r->descr )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__Action( & $r )
{
    $header = array( 'TYPE', 'MSG_TEMPL_ID' );

    $data = array(
        to_html__action_type_e( $r->type ),
        \basic_parser\to_html__int( $r->msg_templ_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ContactPhone( & $r )
{
    $header = array( 'TYPE', 'PHONE_NUMBER' );

    $data = array(
        to_html__ContactPhone_type_e( $r->type ),
        \basic_parser\to_html__string( $r->phone_number )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ContactPhoneWithId( & $r )
{
    $header = array( 'CONTACT_PHONE_ID', 'CONTACT_PHONE' );

    $data = array(
        \basic_parser\to_html__int( $r->contact_phone_id ),
        to_html__ContactPhone( $r->contact_phone )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__Contact( & $r )
{
    $header = array( 'GENDER', 'NAME', 'FIRST_NAME', 'BIRTHDAY', 'NOTICE' );

    $data = array(
        to_html__gender_e( $r->gender ),
        \basic_parser\to_html__string( $r->name ),
        \basic_parser\to_html__string( $r->first_name ),
        \basic_objects\to_html__Date( $r->birthday ),
        \basic_parser\to_html__string( $r->notice )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ExtendedContactInfo( & $r )
{
    $header = array( 'VOICE', 'LANG', 'MAX_TRIES', 'REDIAL_IF_NO_FEEDBACK', 'TIME_WINDOW', 'WEEKDAYS' );

    $data = array(
        to_html__voice_e( $r->voice ),
        \lang_tools\to_html__lang_e( $r->lang ),
        \basic_parser\to_html__int( $r->max_tries ),
        \basic_parser\to_html__bool( $r->redial_if_no_feedback ),
        \basic_objects\to_html__TimeWindow( $r->time_window ),
        \basic_objects\to_html__Weekdays( $r->weekdays )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ReminderAction( & $r )
{
    $header = array( 'TYPE', 'MSG_TEMPL_ID' );

    $data = array(
        to_html__ReminderAction_type_e( $r->type ),
        \basic_parser\to_html__int( $r->msg_templ_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ReminderOptions( & $r )
{
    $header = array( 'VOICE', 'LANG', 'MAX_TRIES', 'REDIAL_IF_NO_FEEDBACK', 'TIME_WINDOW', 'WEEKDAYS' );

    $data = array(
        to_html__voice_e( $r->voice ),
        \lang_tools\to_html__lang_e( $r->lang ),
        \basic_parser\to_html__int( $r->max_tries ),
        \basic_parser\to_html__bool( $r->redial_if_no_feedback ),
        \basic_objects\to_html__TimeWindow( $r->time_window ),
        \basic_objects\to_html__Weekdays( $r->weekdays )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__Reminder( & $r )
{
    $header = array( 'MSG_TEMPL_ID', 'FEEDBACK_TEMPL_ID', 'EFFECTIVE_TIME', 'REMIND_PERIOD', 'PARAMS', 'ACTIONS', 'OPTIONS' );

    $data = array(
        \basic_parser\to_html__int( $r->msg_templ_id ),
        \basic_parser\to_html__int( $r->feedback_templ_id ),
        \basic_parser\to_html__int( $r->effective_time ),
        \basic_parser\to_html__int( $r->remind_period ),
        \basic_parser\to_html__map( $r->params, '\basic_parser\to_html__string', '\basic_parser\to_html__string' ),
        \basic_parser\to_html__map( $r->actions, '\dtmf_tools\to_html__tone_e', '\persek_protocol\to_html__ReminderAction' ),
        to_html__ReminderOptions( $r->options )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// base messages

function to_html__Request( & $r )
{
    $header = array( 'generic_protocol::Request' );

    $data = array(
        \generic_protocol\to_html__Request( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__BackwardMessage( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// messages

function to_html__GetJobInfoRequest( & $r )
{
    $header = array( 'Request', 'USER_ID', 'JOB_IDS' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->user_id ),
        \basic_parser\to_html__vector( $r->job_ids, '\basic_parser\to_html__int' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetJobInfoResponse( & $r )
{
    $header = array( 'BackwardMessage', 'JOBS' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__vector( $r->jobs, '\persek_protocol\to_html__JobInfo' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetJobStatRequest( & $r )
{
    $header = array( 'Request', 'USER_ID', 'JOB_IDS' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->user_id ),
        \basic_parser\to_html__vector( $r->job_ids, '\basic_parser\to_html__int' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetJobStatResponse( & $r )
{
    $header = array( 'BackwardMessage', 'OPEN_JOBS', 'CLOSED_JOBS' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__vector( $r->open_jobs, '\persek_protocol\to_html__OpenJobStatus' ),
        \basic_parser\to_html__vector( $r->closed_jobs, '\persek_protocol\to_html__ClosedJobStatus' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__FindJobRequest( & $r )
{
    $header = array( 'Request', 'USER_ID', 'STATUS', 'CONTACT_REGEX', 'CREATION_TIME_RANGE', 'EXEC_TIME_RANGE', 'UPDATE_TIME_RANGE', 'MAX_RESULTS', 'OFFSET' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->user_id ),
        to_html__FindJobRequest_status_e( $r->status ),
        \basic_parser\to_html__string( $r->contact_regex ),
        \basic_objects\to_html__TimeRange( $r->creation_time_range ),
        \basic_objects\to_html__TimeRange( $r->exec_time_range ),
        \basic_objects\to_html__TimeRange( $r->update_time_range ),
        \basic_parser\to_html__int( $r->max_results ),
        \basic_parser\to_html__int( $r->offset )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__FindJobResponse( & $r )
{
    $header = array( 'BackwardMessage', 'TOTAL_SIZE', 'JOB_IDS' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__int( $r->total_size ),
        \basic_parser\to_html__vector( $r->job_ids, '\basic_parser\to_html__int' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__FindTemplatesRequest( & $r )
{
    $header = array( 'Request', 'USER_ID', 'CATEGORY_ID', 'NAME_REGEX', 'LANG' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->user_id ),
        \basic_parser\to_html__int( $r->category_id ),
        \basic_parser\to_html__string( $r->name_regex ),
        \lang_tools\to_html__lang_e( $r->lang )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__FindTemplatesResponse( & $r )
{
    $header = array( 'BackwardMessage', 'TEMPLATES' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__vector( $r->templates, '\persek_protocol\to_html__TemplateInfo' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__CancelJobRequest( & $r )
{
    $header = array( 'Request', 'JOB_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->job_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__CancelJobResponse( & $r )
{
    $header = array( 'BackwardMessage' );

    $data = array(
        to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__CancelJobsRequest( & $r )
{
    $header = array( 'Request', 'JOB_IDS' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__vector( $r->job_ids, '\basic_parser\to_html__int' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__CancelJobsResponse( & $r )
{
    $header = array( 'BackwardMessage', 'CANCELLED_JOB_IDS', 'FAILED_JOBS' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__vector( $r->cancelled_job_ids, '\basic_parser\to_html__int' ),
        \basic_parser\to_html__vector( $r->failed_jobs, '\persek_protocol\to_html__CancellationFailureReason' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__SayRequest( & $r )
{
    $header = array( 'Request', 'USER_ID', 'CONTACT_ID', 'MSG_TEMPL_ID', 'PARAMS', 'OPTIONS' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->user_id ),
        \basic_parser\to_html__string( $r->contact_id ),
        \basic_parser\to_html__int( $r->msg_templ_id ),
        \basic_parser\to_html__map( $r->params, '\basic_parser\to_html__string', '\basic_parser\to_html__string' ),
        to_html__JobOptions( $r->options )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__SayResponse( & $r )
{
    $header = array( 'BackwardMessage', 'JOB_ID' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__int( $r->job_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__SayFeedbackRequest( & $r )
{
    $header = array( 'Request', 'USER_ID', 'CONTACT_ID', 'MSG_TEMPL_ID', 'FEEDBACK_TEMPL_ID', 'PARAMS', 'ACTIONS', 'OPTIONS' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->user_id ),
        \basic_parser\to_html__string( $r->contact_id ),
        \basic_parser\to_html__int( $r->msg_templ_id ),
        \basic_parser\to_html__int( $r->feedback_templ_id ),
        \basic_parser\to_html__map( $r->params, '\basic_parser\to_html__string', '\basic_parser\to_html__string' ),
        \basic_parser\to_html__map( $r->actions, '\dtmf_tools\to_html__tone_e', '\persek_protocol\to_html__Action' ),
        to_html__JobOptions( $r->options )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__SayFeedbackResponse( & $r )
{
    $header = array( 'BackwardMessage', 'JOB_ID' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__int( $r->job_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AddContactPhoneRequest( & $r )
{
    $header = array( 'Request', 'CONTACT_ID', 'CONTACT_PHONE' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->contact_id ),
        to_html__ContactPhone( $r->contact_phone )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AddContactPhoneResponse( & $r )
{
    $header = array( 'BackwardMessage', 'CONTACT_PHONE_ID' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__int( $r->contact_phone_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ModifyContactPhoneRequest( & $r )
{
    $header = array( 'Request', 'CONTACT_PHONE_ID', 'CONTACT_PHONE' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->contact_phone_id ),
        to_html__ContactPhone( $r->contact_phone )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ModifyContactPhoneResponse( & $r )
{
    $header = array( 'BackwardMessage' );

    $data = array(
        to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__DeleteContactPhoneRequest( & $r )
{
    $header = array( 'Request', 'CONTACT_PHONE_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->contact_phone_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__DeleteContactPhoneResponse( & $r )
{
    $header = array( 'BackwardMessage' );

    $data = array(
        to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetContactPhoneRequest( & $r )
{
    $header = array( 'Request', 'CONTACT_PHONE_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->contact_phone_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetContactPhoneResponse( & $r )
{
    $header = array( 'BackwardMessage', 'CONTACT_ID', 'CONTACT_PHONE' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__int( $r->contact_id ),
        to_html__ContactPhone( $r->contact_phone )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AddContactRequest( & $r )
{
    $header = array( 'Request', 'USER_ID', 'CONTACT' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->user_id ),
        to_html__Contact( $r->contact )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AddContactResponse( & $r )
{
    $header = array( 'BackwardMessage', 'CONTACT_ID' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__int( $r->contact_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ModifyContactRequest( & $r )
{
    $header = array( 'Request', 'CONTACT_ID', 'CONTACT' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->contact_id ),
        to_html__Contact( $r->contact )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ModifyContactResponse( & $r )
{
    $header = array( 'BackwardMessage' );

    $data = array(
        to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__DeleteContactRequest( & $r )
{
    $header = array( 'Request', 'CONTACT_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->contact_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__DeleteContactResponse( & $r )
{
    $header = array( 'BackwardMessage' );

    $data = array(
        to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetContactRequest( & $r )
{
    $header = array( 'Request', 'CONTACT_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->contact_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetContactResponse( & $r )
{
    $header = array( 'BackwardMessage', 'CONTACT', 'CONTACT_PHONE_IDS' );

    $data = array(
        to_html__BackwardMessage( $r ),
        to_html__Contact( $r->contact ),
        \basic_parser\to_html__vector( $r->contact_phone_ids, '\basic_parser\to_html__int' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetContactWithPhonesRequest( & $r )
{
    $header = array( 'Request', 'CONTACT_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->contact_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetContactWithPhonesResponse( & $r )
{
    $header = array( 'BackwardMessage', 'CONTACT', 'CONTACT_PHONES' );

    $data = array(
        to_html__BackwardMessage( $r ),
        to_html__Contact( $r->contact ),
        \basic_parser\to_html__vector( $r->contact_phones, '\persek_protocol\to_html__ContactPhoneWithId' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetContactExtRequest( & $r )
{
    $header = array( 'Request', 'CONTACT_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->contact_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetContactExtResponse( & $r )
{
    $header = array( 'BackwardMessage', 'CONTACT', 'CONTACT_PHONES', 'EXTENDED_INFO' );

    $data = array(
        to_html__BackwardMessage( $r ),
        to_html__Contact( $r->contact ),
        \basic_parser\to_html__vector( $r->contact_phones, '\persek_protocol\to_html__ContactPhoneWithId' ),
        to_html__ExtendedContactInfo( $r->extended_info )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetExtendedContactInfoRequest( & $r )
{
    $header = array( 'Request', 'CONTACT_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->contact_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetExtendedContactInfoResponse( & $r )
{
    $header = array( 'BackwardMessage', 'EXTENDED_INFO' );

    $data = array(
        to_html__BackwardMessage( $r ),
        to_html__ExtendedContactInfo( $r->extended_info )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__SetExtendedContactInfoRequest( & $r )
{
    $header = array( 'Request', 'CONTACT_ID', 'EXTENDED_INFO' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->contact_id ),
        to_html__ExtendedContactInfo( $r->extended_info )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__SetExtendedContactInfoResponse( & $r )
{
    $header = array( 'BackwardMessage' );

    $data = array(
        to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AddReminderRequest( & $r )
{
    $header = array( 'Request', 'CONTACT_PHONE_ID', 'REMINDER' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->contact_phone_id ),
        to_html__Reminder( $r->reminder )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AddReminderResponse( & $r )
{
    $header = array( 'BackwardMessage', 'JOB_ID' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__int( $r->job_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ModifyReminderRequest( & $r )
{
    $header = array( 'Request', 'JOB_ID', 'CONTACT_PHONE_ID', 'REMINDER' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->job_id ),
        \basic_parser\to_html__int( $r->contact_phone_id ),
        to_html__Reminder( $r->reminder )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ModifyReminderResponse( & $r )
{
    $header = array( 'BackwardMessage' );

    $data = array(
        to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetReminderRequest( & $r )
{
    $header = array( 'Request', 'JOB_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->job_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetReminderResponse( & $r )
{
    $header = array( 'BackwardMessage', 'CONTACT_ID', 'CONTACT_PHONE_ID', 'CONTACT_PHONE', 'REMINDER' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__int( $r->contact_id ),
        \basic_parser\to_html__int( $r->contact_phone_id ),
        \basic_parser\to_html__string( $r->contact_phone ),
        to_html__Reminder( $r->reminder )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetReminderStatusRequest( & $r )
{
    $header = array( 'Request', 'USER_ID', 'SEARCH_FILTER', 'EFFECTIVE_DATE_TIME_RANGE', 'PAGE_SIZE', 'PAGE_NUMBER' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->user_id ),
        \basic_parser\to_html__string( $r->search_filter ),
        \basic_objects\to_html__TimeRange( $r->effective_date_time_range ),
        \basic_parser\to_html__int( $r->page_size ),
        \basic_parser\to_html__int( $r->page_number )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// generic

function to_html( $obj )
{
    $handler_map = array(
        // objects
        'persek_protocol\JobOptions'         => 'to_html__JobOptions',
        'persek_protocol\JobInfo'         => 'to_html__JobInfo',
        'persek_protocol\ClosedJobStatus'         => 'to_html__ClosedJobStatus',
        'persek_protocol\OpenJobStatus'         => 'to_html__OpenJobStatus',
        'persek_protocol\TemplateInfo'         => 'to_html__TemplateInfo',
        'persek_protocol\CancellationFailureReason'         => 'to_html__CancellationFailureReason',
        'persek_protocol\Action'         => 'to_html__Action',
        'persek_protocol\ContactPhone'         => 'to_html__ContactPhone',
        'persek_protocol\ContactPhoneWithId'         => 'to_html__ContactPhoneWithId',
        'persek_protocol\Contact'         => 'to_html__Contact',
        'persek_protocol\ExtendedContactInfo'         => 'to_html__ExtendedContactInfo',
        'persek_protocol\ReminderAction'         => 'to_html__ReminderAction',
        'persek_protocol\ReminderOptions'         => 'to_html__ReminderOptions',
        'persek_protocol\Reminder'         => 'to_html__Reminder',
        // messages
        'persek_protocol\GetJobInfoRequest'         => 'to_html__GetJobInfoRequest',
        'persek_protocol\GetJobInfoResponse'         => 'to_html__GetJobInfoResponse',
        'persek_protocol\GetJobStatRequest'         => 'to_html__GetJobStatRequest',
        'persek_protocol\GetJobStatResponse'         => 'to_html__GetJobStatResponse',
        'persek_protocol\FindJobRequest'         => 'to_html__FindJobRequest',
        'persek_protocol\FindJobResponse'         => 'to_html__FindJobResponse',
        'persek_protocol\FindTemplatesRequest'         => 'to_html__FindTemplatesRequest',
        'persek_protocol\FindTemplatesResponse'         => 'to_html__FindTemplatesResponse',
        'persek_protocol\CancelJobRequest'         => 'to_html__CancelJobRequest',
        'persek_protocol\CancelJobResponse'         => 'to_html__CancelJobResponse',
        'persek_protocol\CancelJobsRequest'         => 'to_html__CancelJobsRequest',
        'persek_protocol\CancelJobsResponse'         => 'to_html__CancelJobsResponse',
        'persek_protocol\SayRequest'         => 'to_html__SayRequest',
        'persek_protocol\SayResponse'         => 'to_html__SayResponse',
        'persek_protocol\SayFeedbackRequest'         => 'to_html__SayFeedbackRequest',
        'persek_protocol\SayFeedbackResponse'         => 'to_html__SayFeedbackResponse',
        'persek_protocol\AddContactPhoneRequest'         => 'to_html__AddContactPhoneRequest',
        'persek_protocol\AddContactPhoneResponse'         => 'to_html__AddContactPhoneResponse',
        'persek_protocol\ModifyContactPhoneRequest'         => 'to_html__ModifyContactPhoneRequest',
        'persek_protocol\ModifyContactPhoneResponse'         => 'to_html__ModifyContactPhoneResponse',
        'persek_protocol\DeleteContactPhoneRequest'         => 'to_html__DeleteContactPhoneRequest',
        'persek_protocol\DeleteContactPhoneResponse'         => 'to_html__DeleteContactPhoneResponse',
        'persek_protocol\GetContactPhoneRequest'         => 'to_html__GetContactPhoneRequest',
        'persek_protocol\GetContactPhoneResponse'         => 'to_html__GetContactPhoneResponse',
        'persek_protocol\AddContactRequest'         => 'to_html__AddContactRequest',
        'persek_protocol\AddContactResponse'         => 'to_html__AddContactResponse',
        'persek_protocol\ModifyContactRequest'         => 'to_html__ModifyContactRequest',
        'persek_protocol\ModifyContactResponse'         => 'to_html__ModifyContactResponse',
        'persek_protocol\DeleteContactRequest'         => 'to_html__DeleteContactRequest',
        'persek_protocol\DeleteContactResponse'         => 'to_html__DeleteContactResponse',
        'persek_protocol\GetContactRequest'         => 'to_html__GetContactRequest',
        'persek_protocol\GetContactResponse'         => 'to_html__GetContactResponse',
        'persek_protocol\GetContactWithPhonesRequest'         => 'to_html__GetContactWithPhonesRequest',
        'persek_protocol\GetContactWithPhonesResponse'         => 'to_html__GetContactWithPhonesResponse',
        'persek_protocol\GetContactExtRequest'         => 'to_html__GetContactExtRequest',
        'persek_protocol\GetContactExtResponse'         => 'to_html__GetContactExtResponse',
        'persek_protocol\GetExtendedContactInfoRequest'         => 'to_html__GetExtendedContactInfoRequest',
        'persek_protocol\GetExtendedContactInfoResponse'         => 'to_html__GetExtendedContactInfoResponse',
        'persek_protocol\SetExtendedContactInfoRequest'         => 'to_html__SetExtendedContactInfoRequest',
        'persek_protocol\SetExtendedContactInfoResponse'         => 'to_html__SetExtendedContactInfoResponse',
        'persek_protocol\AddReminderRequest'         => 'to_html__AddReminderRequest',
        'persek_protocol\AddReminderResponse'         => 'to_html__AddReminderResponse',
        'persek_protocol\ModifyReminderRequest'         => 'to_html__ModifyReminderRequest',
        'persek_protocol\ModifyReminderResponse'         => 'to_html__ModifyReminderResponse',
        'persek_protocol\GetReminderRequest'         => 'to_html__GetReminderRequest',
        'persek_protocol\GetReminderResponse'         => 'to_html__GetReminderResponse',
        'persek_protocol\GetReminderStatusRequest'         => 'to_html__GetReminderStatusRequest',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\persek_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \generic_protocol\to_html( $obj );
}

# namespace_end persek_protocol


?>
