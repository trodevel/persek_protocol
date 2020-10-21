<?php

namespace persek_protocol;


// own includes
require_once __DIR__.'/../persek_protocol/protocol.php';
require_once __DIR__.'/../persek_protocol/dummy_creator.php';
require_once __DIR__.'/../persek_protocol/html_helper.php';

# objects

function example_JobOptions()
{
    $obj = \persek_protocol\create_dummy__JobOptions();

    echo "JobOptions : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_JobInfo()
{
    $obj = \persek_protocol\create_dummy__JobInfo();

    echo "JobInfo : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_ClosedJobStatus()
{
    $obj = \persek_protocol\create_dummy__ClosedJobStatus();

    echo "ClosedJobStatus : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_OpenJobStatus()
{
    $obj = \persek_protocol\create_dummy__OpenJobStatus();

    echo "OpenJobStatus : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_TemplateInfo()
{
    $obj = \persek_protocol\create_dummy__TemplateInfo();

    echo "TemplateInfo : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_CancellationFailureReason()
{
    $obj = \persek_protocol\create_dummy__CancellationFailureReason();

    echo "CancellationFailureReason : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_Action()
{
    $obj = \persek_protocol\create_dummy__Action();

    echo "Action : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_ContactPhone()
{
    $obj = \persek_protocol\create_dummy__ContactPhone();

    echo "ContactPhone : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_ContactPhoneWithId()
{
    $obj = \persek_protocol\create_dummy__ContactPhoneWithId();

    echo "ContactPhoneWithId : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_Contact()
{
    $obj = \persek_protocol\create_dummy__Contact();

    echo "Contact : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_ExtendedContactInfo()
{
    $obj = \persek_protocol\create_dummy__ExtendedContactInfo();

    echo "ExtendedContactInfo : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_ReminderAction()
{
    $obj = \persek_protocol\create_dummy__ReminderAction();

    echo "ReminderAction : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_ReminderOptions()
{
    $obj = \persek_protocol\create_dummy__ReminderOptions();

    echo "ReminderOptions : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_Reminder()
{
    $obj = \persek_protocol\create_dummy__Reminder();

    echo "Reminder : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}


# messages

function example_GetJobInfoRequest()
{
    $obj = \persek_protocol\create_dummy__GetJobInfoRequest();

    echo "GetJobInfoRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetJobInfoResponse()
{
    $obj = \persek_protocol\create_dummy__GetJobInfoResponse();

    echo "GetJobInfoResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetJobStatRequest()
{
    $obj = \persek_protocol\create_dummy__GetJobStatRequest();

    echo "GetJobStatRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetJobStatResponse()
{
    $obj = \persek_protocol\create_dummy__GetJobStatResponse();

    echo "GetJobStatResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_FindJobRequest()
{
    $obj = \persek_protocol\create_dummy__FindJobRequest();

    echo "FindJobRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_FindJobResponse()
{
    $obj = \persek_protocol\create_dummy__FindJobResponse();

    echo "FindJobResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_FindTemplatesRequest()
{
    $obj = \persek_protocol\create_dummy__FindTemplatesRequest();

    echo "FindTemplatesRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_FindTemplatesResponse()
{
    $obj = \persek_protocol\create_dummy__FindTemplatesResponse();

    echo "FindTemplatesResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_CancelJobRequest()
{
    $obj = \persek_protocol\create_dummy__CancelJobRequest();

    echo "CancelJobRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_CancelJobResponse()
{
    $obj = \persek_protocol\create_dummy__CancelJobResponse();

    echo "CancelJobResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_CancelJobsRequest()
{
    $obj = \persek_protocol\create_dummy__CancelJobsRequest();

    echo "CancelJobsRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_CancelJobsResponse()
{
    $obj = \persek_protocol\create_dummy__CancelJobsResponse();

    echo "CancelJobsResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_SayRequest()
{
    $obj = \persek_protocol\create_dummy__SayRequest();

    echo "SayRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_SayResponse()
{
    $obj = \persek_protocol\create_dummy__SayResponse();

    echo "SayResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_SayFeedbackRequest()
{
    $obj = \persek_protocol\create_dummy__SayFeedbackRequest();

    echo "SayFeedbackRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_SayFeedbackResponse()
{
    $obj = \persek_protocol\create_dummy__SayFeedbackResponse();

    echo "SayFeedbackResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_AddContactPhoneRequest()
{
    $obj = \persek_protocol\create_dummy__AddContactPhoneRequest();

    echo "AddContactPhoneRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_AddContactPhoneResponse()
{
    $obj = \persek_protocol\create_dummy__AddContactPhoneResponse();

    echo "AddContactPhoneResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_ModifyContactPhoneRequest()
{
    $obj = \persek_protocol\create_dummy__ModifyContactPhoneRequest();

    echo "ModifyContactPhoneRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_ModifyContactPhoneResponse()
{
    $obj = \persek_protocol\create_dummy__ModifyContactPhoneResponse();

    echo "ModifyContactPhoneResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_DeleteContactPhoneRequest()
{
    $obj = \persek_protocol\create_dummy__DeleteContactPhoneRequest();

    echo "DeleteContactPhoneRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_DeleteContactPhoneResponse()
{
    $obj = \persek_protocol\create_dummy__DeleteContactPhoneResponse();

    echo "DeleteContactPhoneResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetContactPhoneRequest()
{
    $obj = \persek_protocol\create_dummy__GetContactPhoneRequest();

    echo "GetContactPhoneRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetContactPhoneResponse()
{
    $obj = \persek_protocol\create_dummy__GetContactPhoneResponse();

    echo "GetContactPhoneResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_AddContactRequest()
{
    $obj = \persek_protocol\create_dummy__AddContactRequest();

    echo "AddContactRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_AddContactResponse()
{
    $obj = \persek_protocol\create_dummy__AddContactResponse();

    echo "AddContactResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_ModifyContactRequest()
{
    $obj = \persek_protocol\create_dummy__ModifyContactRequest();

    echo "ModifyContactRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_ModifyContactResponse()
{
    $obj = \persek_protocol\create_dummy__ModifyContactResponse();

    echo "ModifyContactResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_DeleteContactRequest()
{
    $obj = \persek_protocol\create_dummy__DeleteContactRequest();

    echo "DeleteContactRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_DeleteContactResponse()
{
    $obj = \persek_protocol\create_dummy__DeleteContactResponse();

    echo "DeleteContactResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetContactRequest()
{
    $obj = \persek_protocol\create_dummy__GetContactRequest();

    echo "GetContactRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetContactResponse()
{
    $obj = \persek_protocol\create_dummy__GetContactResponse();

    echo "GetContactResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetContactWithPhonesRequest()
{
    $obj = \persek_protocol\create_dummy__GetContactWithPhonesRequest();

    echo "GetContactWithPhonesRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetContactWithPhonesResponse()
{
    $obj = \persek_protocol\create_dummy__GetContactWithPhonesResponse();

    echo "GetContactWithPhonesResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetContactExtRequest()
{
    $obj = \persek_protocol\create_dummy__GetContactExtRequest();

    echo "GetContactExtRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetContactExtResponse()
{
    $obj = \persek_protocol\create_dummy__GetContactExtResponse();

    echo "GetContactExtResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetExtendedContactInfoRequest()
{
    $obj = \persek_protocol\create_dummy__GetExtendedContactInfoRequest();

    echo "GetExtendedContactInfoRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetExtendedContactInfoResponse()
{
    $obj = \persek_protocol\create_dummy__GetExtendedContactInfoResponse();

    echo "GetExtendedContactInfoResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_SetExtendedContactInfoRequest()
{
    $obj = \persek_protocol\create_dummy__SetExtendedContactInfoRequest();

    echo "SetExtendedContactInfoRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_SetExtendedContactInfoResponse()
{
    $obj = \persek_protocol\create_dummy__SetExtendedContactInfoResponse();

    echo "SetExtendedContactInfoResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_AddReminderRequest()
{
    $obj = \persek_protocol\create_dummy__AddReminderRequest();

    echo "AddReminderRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_AddReminderResponse()
{
    $obj = \persek_protocol\create_dummy__AddReminderResponse();

    echo "AddReminderResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_ModifyReminderRequest()
{
    $obj = \persek_protocol\create_dummy__ModifyReminderRequest();

    echo "ModifyReminderRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_ModifyReminderResponse()
{
    $obj = \persek_protocol\create_dummy__ModifyReminderResponse();

    echo "ModifyReminderResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetReminderRequest()
{
    $obj = \persek_protocol\create_dummy__GetReminderRequest();

    echo "GetReminderRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetReminderResponse()
{
    $obj = \persek_protocol\create_dummy__GetReminderResponse();

    echo "GetReminderResponse : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetReminderStatusRequest()
{
    $obj = \persek_protocol\create_dummy__GetReminderStatusRequest();

    echo "GetReminderStatusRequest : HTML : " . \persek_protocol\to_html( $obj ) . "<br>\n";
}


{
    // objects

    example_JobOptions();
    example_JobInfo();
    example_ClosedJobStatus();
    example_OpenJobStatus();
    example_TemplateInfo();
    example_CancellationFailureReason();
    example_Action();
    example_ContactPhone();
    example_ContactPhoneWithId();
    example_Contact();
    example_ExtendedContactInfo();
    example_ReminderAction();
    example_ReminderOptions();
    example_Reminder();

    // messages

    example_GetJobInfoRequest();
    example_GetJobInfoResponse();
    example_GetJobStatRequest();
    example_GetJobStatResponse();
    example_FindJobRequest();
    example_FindJobResponse();
    example_FindTemplatesRequest();
    example_FindTemplatesResponse();
    example_CancelJobRequest();
    example_CancelJobResponse();
    example_CancelJobsRequest();
    example_CancelJobsResponse();
    example_SayRequest();
    example_SayResponse();
    example_SayFeedbackRequest();
    example_SayFeedbackResponse();
    example_AddContactPhoneRequest();
    example_AddContactPhoneResponse();
    example_ModifyContactPhoneRequest();
    example_ModifyContactPhoneResponse();
    example_DeleteContactPhoneRequest();
    example_DeleteContactPhoneResponse();
    example_GetContactPhoneRequest();
    example_GetContactPhoneResponse();
    example_AddContactRequest();
    example_AddContactResponse();
    example_ModifyContactRequest();
    example_ModifyContactResponse();
    example_DeleteContactRequest();
    example_DeleteContactResponse();
    example_GetContactRequest();
    example_GetContactResponse();
    example_GetContactWithPhonesRequest();
    example_GetContactWithPhonesResponse();
    example_GetContactExtRequest();
    example_GetContactExtResponse();
    example_GetExtendedContactInfoRequest();
    example_GetExtendedContactInfoResponse();
    example_SetExtendedContactInfoRequest();
    example_SetExtendedContactInfoResponse();
    example_AddReminderRequest();
    example_AddReminderResponse();
    example_ModifyReminderRequest();
    example_ModifyReminderResponse();
    example_GetReminderRequest();
    example_GetReminderResponse();
    example_GetReminderStatusRequest();

}

// namespace_end persek_protocol


?>
