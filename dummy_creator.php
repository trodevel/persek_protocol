<?php

namespace persek_protocol;


// includes
require_once __DIR__.'/../generic_protocol/dummy_creator.php';
require_once __DIR__.'/../basic_parser/dummy_creator.php';
require_once __DIR__.'/../basic_objects/dummy_creator.php';
require_once __DIR__.'/../dtmf_tools/dummy_creator.php';
require_once __DIR__.'/../lang_tools/dummy_creator.php';
require_once 'object_initializer.php';

// enums

function create_dummy__voice_e()
{
    $res = voice_e__UNDEF;

    return $res;
}

function create_dummy__urgency_e()
{
    $res = urgency_e__UNDEF;

    return $res;
}

function create_dummy__JobInfo_type_e()
{
    $res = JobInfo_type_e__UNDEF;

    return $res;
}

function create_dummy__exit_status_e()
{
    $res = exit_status_e__DONE;

    return $res;
}

function create_dummy__OpenJobStatus_state_e()
{
    $res = OpenJobStatus_state_e__IDLE;

    return $res;
}

function create_dummy__FindJobRequest_status_e()
{
    $res = FindJobRequest_status_e__ANY;

    return $res;
}

function create_dummy__action_type_e()
{
    $res = action_type_e__NONE;

    return $res;
}

function create_dummy__ContactPhone_type_e()
{
    $res = ContactPhone_type_e__DFLT;

    return $res;
}

function create_dummy__gender_e()
{
    $res = gender_e__UNDEF;

    return $res;
}

function create_dummy__ReminderAction_type_e()
{
    $res = ReminderAction_type_e__NONE;

    return $res;
}

// objects

function create_dummy__JobOptions()
{
    $res = new JobOptions;

    initialize__JobOptions( $res
        , create_dummy__voice_e()
        , create_dummy__urgency_e()
        , \lang_tools\create_dummy__lang_e()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__bool()
        , \basic_objects\create_dummy__TimeWindow()
        , \basic_objects\create_dummy__Weekdays()
        );
    return $res;
}

function create_dummy__JobInfo()
{
    $res = new JobInfo;

    initialize__JobInfo( $res
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        , create_dummy__JobInfo_type_e()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , create_dummy__JobOptions()
        );
    return $res;
}

function create_dummy__ClosedJobStatus()
{
    $res = new ClosedJobStatus;

    initialize__ClosedJobStatus( $res
        , \basic_parser\create_dummy__int32()
        , create_dummy__exit_status_e()
        , \basic_parser\create_dummy__vector( '\basic_parser\create_dummy__int32' ) // Array
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__OpenJobStatus()
{
    $res = new OpenJobStatus;

    initialize__OpenJobStatus( $res
        , \basic_parser\create_dummy__int32()
        , create_dummy__OpenJobStatus_state_e()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__TemplateInfo()
{
    $res = new TemplateInfo;

    initialize__TemplateInfo( $res
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__string()
        , \lang_tools\create_dummy__lang_e()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__vector( '\basic_parser\create_dummy__string' ) // Array
        );
    return $res;
}

function create_dummy__CancellationFailureReason()
{
    $res = new CancellationFailureReason;

    initialize__CancellationFailureReason( $res
        , \basic_parser\create_dummy__int32()
        , \generic_protocol\create_dummy__ErrorResponse_type_e()
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__Action()
{
    $res = new Action;

    initialize__Action( $res
        , create_dummy__action_type_e()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__ContactPhone()
{
    $res = new ContactPhone;

    initialize__ContactPhone( $res
        , create_dummy__ContactPhone_type_e()
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__ContactPhoneWithId()
{
    $res = new ContactPhoneWithId;

    initialize__ContactPhoneWithId( $res
        , \basic_parser\create_dummy__int32()
        , create_dummy__ContactPhone()
        );
    return $res;
}

function create_dummy__Contact()
{
    $res = new Contact;

    initialize__Contact( $res
        , create_dummy__gender_e()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_objects\create_dummy__Date()
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__ExtendedContactInfo()
{
    $res = new ExtendedContactInfo;

    initialize__ExtendedContactInfo( $res
        , create_dummy__voice_e()
        , \lang_tools\create_dummy__lang_e()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__bool()
        , \basic_objects\create_dummy__TimeWindow()
        , \basic_objects\create_dummy__Weekdays()
        );
    return $res;
}

function create_dummy__ReminderAction()
{
    $res = new ReminderAction;

    initialize__ReminderAction( $res
        , create_dummy__ReminderAction_type_e()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__ReminderOptions()
{
    $res = new ReminderOptions;

    initialize__ReminderOptions( $res
        , create_dummy__voice_e()
        , \lang_tools\create_dummy__lang_e()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__bool()
        , \basic_objects\create_dummy__TimeWindow()
        , \basic_objects\create_dummy__Weekdays()
        );
    return $res;
}

function create_dummy__Reminder()
{
    $res = new Reminder;

    initialize__Reminder( $res
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__map( '\basic_parser\create_dummy__string',  '\basic_parser\create_dummy__string' ) // Map
        , \basic_parser\create_dummy__map( '\dtmf_tools\create_dummy__tone_e',  '\persek_protocol\create_dummy__ReminderAction' ) // Map
        , create_dummy__ReminderOptions()
        );
    return $res;
}

// messages

function create_dummy__GetJobInfoRequest()
{
    $res = new GetJobInfoRequest;

    initialize__GetJobInfoRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__vector( '\basic_parser\create_dummy__int32' ) // Array
        );
    return $res;
}

function create_dummy__GetJobInfoResponse()
{
    $res = new GetJobInfoResponse;

    initialize__GetJobInfoResponse( $res
        , \basic_parser\create_dummy__vector( '\persek_protocol\create_dummy__JobInfo' ) // Array
        );
    return $res;
}

function create_dummy__GetJobStatRequest()
{
    $res = new GetJobStatRequest;

    initialize__GetJobStatRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__vector( '\basic_parser\create_dummy__int32' ) // Array
        );
    return $res;
}

function create_dummy__GetJobStatResponse()
{
    $res = new GetJobStatResponse;

    initialize__GetJobStatResponse( $res
        , \basic_parser\create_dummy__vector( '\persek_protocol\create_dummy__OpenJobStatus' ) // Array
        , \basic_parser\create_dummy__vector( '\persek_protocol\create_dummy__ClosedJobStatus' ) // Array
        );
    return $res;
}

function create_dummy__FindJobRequest()
{
    $res = new FindJobRequest;

    initialize__FindJobRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , create_dummy__FindJobRequest_status_e()
        , \basic_parser\create_dummy__string()
        , \basic_objects\create_dummy__TimeRange()
        , \basic_objects\create_dummy__TimeRange()
        , \basic_objects\create_dummy__TimeRange()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__FindJobResponse()
{
    $res = new FindJobResponse;

    initialize__FindJobResponse( $res
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__vector( '\basic_parser\create_dummy__int32' ) // Array
        );
    return $res;
}

function create_dummy__FindTemplatesRequest()
{
    $res = new FindTemplatesRequest;

    initialize__FindTemplatesRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__string()
        , \lang_tools\create_dummy__lang_e()
        );
    return $res;
}

function create_dummy__FindTemplatesResponse()
{
    $res = new FindTemplatesResponse;

    initialize__FindTemplatesResponse( $res
        , \basic_parser\create_dummy__vector( '\persek_protocol\create_dummy__TemplateInfo' ) // Array
        );
    return $res;
}

function create_dummy__CancelJobRequest()
{
    $res = new CancelJobRequest;

    initialize__CancelJobRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__CancelJobResponse()
{
    $res = new CancelJobResponse;

    initialize__CancelJobResponse( $res
        );
    return $res;
}

function create_dummy__CancelJobsRequest()
{
    $res = new CancelJobsRequest;

    initialize__CancelJobsRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__vector( '\basic_parser\create_dummy__int32' ) // Array
        );
    return $res;
}

function create_dummy__CancelJobsResponse()
{
    $res = new CancelJobsResponse;

    initialize__CancelJobsResponse( $res
        , \basic_parser\create_dummy__vector( '\basic_parser\create_dummy__int32' ) // Array
        , \basic_parser\create_dummy__vector( '\persek_protocol\create_dummy__CancellationFailureReason' ) // Array
        );
    return $res;
}

function create_dummy__SayRequest()
{
    $res = new SayRequest;

    initialize__SayRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__map( '\basic_parser\create_dummy__string',  '\basic_parser\create_dummy__string' ) // Map
        , create_dummy__JobOptions()
        );
    return $res;
}

function create_dummy__SayResponse()
{
    $res = new SayResponse;

    initialize__SayResponse( $res
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__SayFeedbackRequest()
{
    $res = new SayFeedbackRequest;

    initialize__SayFeedbackRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__map( '\basic_parser\create_dummy__string',  '\basic_parser\create_dummy__string' ) // Map
        , \basic_parser\create_dummy__map( '\dtmf_tools\create_dummy__tone_e',  '\persek_protocol\create_dummy__Action' ) // Map
        , create_dummy__JobOptions()
        );
    return $res;
}

function create_dummy__SayFeedbackResponse()
{
    $res = new SayFeedbackResponse;

    initialize__SayFeedbackResponse( $res
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__AddContactPhoneRequest()
{
    $res = new AddContactPhoneRequest;

    initialize__AddContactPhoneRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , create_dummy__ContactPhone()
        );
    return $res;
}

function create_dummy__AddContactPhoneResponse()
{
    $res = new AddContactPhoneResponse;

    initialize__AddContactPhoneResponse( $res
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__ModifyContactPhoneRequest()
{
    $res = new ModifyContactPhoneRequest;

    initialize__ModifyContactPhoneRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , create_dummy__ContactPhone()
        );
    return $res;
}

function create_dummy__ModifyContactPhoneResponse()
{
    $res = new ModifyContactPhoneResponse;

    initialize__ModifyContactPhoneResponse( $res
        );
    return $res;
}

function create_dummy__DeleteContactPhoneRequest()
{
    $res = new DeleteContactPhoneRequest;

    initialize__DeleteContactPhoneRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__DeleteContactPhoneResponse()
{
    $res = new DeleteContactPhoneResponse;

    initialize__DeleteContactPhoneResponse( $res
        );
    return $res;
}

function create_dummy__GetContactPhoneRequest()
{
    $res = new GetContactPhoneRequest;

    initialize__GetContactPhoneRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__GetContactPhoneResponse()
{
    $res = new GetContactPhoneResponse;

    initialize__GetContactPhoneResponse( $res
        , \basic_parser\create_dummy__int32()
        , create_dummy__ContactPhone()
        );
    return $res;
}

function create_dummy__AddContactRequest()
{
    $res = new AddContactRequest;

    initialize__AddContactRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , create_dummy__Contact()
        );
    return $res;
}

function create_dummy__AddContactResponse()
{
    $res = new AddContactResponse;

    initialize__AddContactResponse( $res
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__ModifyContactRequest()
{
    $res = new ModifyContactRequest;

    initialize__ModifyContactRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , create_dummy__Contact()
        );
    return $res;
}

function create_dummy__ModifyContactResponse()
{
    $res = new ModifyContactResponse;

    initialize__ModifyContactResponse( $res
        );
    return $res;
}

function create_dummy__DeleteContactRequest()
{
    $res = new DeleteContactRequest;

    initialize__DeleteContactRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__DeleteContactResponse()
{
    $res = new DeleteContactResponse;

    initialize__DeleteContactResponse( $res
        );
    return $res;
}

function create_dummy__GetContactRequest()
{
    $res = new GetContactRequest;

    initialize__GetContactRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__GetContactResponse()
{
    $res = new GetContactResponse;

    initialize__GetContactResponse( $res
        , create_dummy__Contact()
        , \basic_parser\create_dummy__vector( '\basic_parser\create_dummy__int32' ) // Array
        );
    return $res;
}

function create_dummy__GetContactWithPhonesRequest()
{
    $res = new GetContactWithPhonesRequest;

    initialize__GetContactWithPhonesRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__GetContactWithPhonesResponse()
{
    $res = new GetContactWithPhonesResponse;

    initialize__GetContactWithPhonesResponse( $res
        , create_dummy__Contact()
        , \basic_parser\create_dummy__vector( '\persek_protocol\create_dummy__ContactPhoneWithId' ) // Array
        );
    return $res;
}

function create_dummy__GetContactExtRequest()
{
    $res = new GetContactExtRequest;

    initialize__GetContactExtRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__GetContactExtResponse()
{
    $res = new GetContactExtResponse;

    initialize__GetContactExtResponse( $res
        , create_dummy__Contact()
        , \basic_parser\create_dummy__vector( '\persek_protocol\create_dummy__ContactPhoneWithId' ) // Array
        , create_dummy__ExtendedContactInfo()
        );
    return $res;
}

function create_dummy__GetExtendedContactInfoRequest()
{
    $res = new GetExtendedContactInfoRequest;

    initialize__GetExtendedContactInfoRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__GetExtendedContactInfoResponse()
{
    $res = new GetExtendedContactInfoResponse;

    initialize__GetExtendedContactInfoResponse( $res
        , create_dummy__ExtendedContactInfo()
        );
    return $res;
}

function create_dummy__SetExtendedContactInfoRequest()
{
    $res = new SetExtendedContactInfoRequest;

    initialize__SetExtendedContactInfoRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , create_dummy__ExtendedContactInfo()
        );
    return $res;
}

function create_dummy__SetExtendedContactInfoResponse()
{
    $res = new SetExtendedContactInfoResponse;

    initialize__SetExtendedContactInfoResponse( $res
        );
    return $res;
}

function create_dummy__AddReminderRequest()
{
    $res = new AddReminderRequest;

    initialize__AddReminderRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , create_dummy__Reminder()
        );
    return $res;
}

function create_dummy__AddReminderResponse()
{
    $res = new AddReminderResponse;

    initialize__AddReminderResponse( $res
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__ModifyReminderRequest()
{
    $res = new ModifyReminderRequest;

    initialize__ModifyReminderRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        , create_dummy__Reminder()
        );
    return $res;
}

function create_dummy__ModifyReminderResponse()
{
    $res = new ModifyReminderResponse;

    initialize__ModifyReminderResponse( $res
        );
    return $res;
}

function create_dummy__GetReminderRequest()
{
    $res = new GetReminderRequest;

    initialize__GetReminderRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__GetReminderResponse()
{
    $res = new GetReminderResponse;

    initialize__GetReminderResponse( $res
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__string()
        , create_dummy__Reminder()
        );
    return $res;
}

function create_dummy__GetReminderStatusRequest()
{
    $res = new GetReminderStatusRequest;

    initialize__GetReminderStatusRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__string()
        , \basic_objects\create_dummy__TimeRange()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

# namespace_end persek_protocol


?>
