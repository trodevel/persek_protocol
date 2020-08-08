<?php

namespace persek_protocol;


// includes
require_once 'protocol.php';
require_once 'dummy_creator.php';
require_once 'str_helper.php';
require_once 'request_encoder.php';

# objects

function example_JobOptions()
{
    $obj = \persek_protocol\create_dummy__JobOptions();

    echo "JobOptions : STR : " . \persek_protocol\to_string( $obj ) . "\n";
}

function example_JobInfo()
{
    $obj = \persek_protocol\create_dummy__JobInfo();

    echo "JobInfo : STR : " . \persek_protocol\to_string( $obj ) . "\n";
}

function example_ClosedJobStatus()
{
    $obj = \persek_protocol\create_dummy__ClosedJobStatus();

    echo "ClosedJobStatus : STR : " . \persek_protocol\to_string( $obj ) . "\n";
}

function example_OpenJobStatus()
{
    $obj = \persek_protocol\create_dummy__OpenJobStatus();

    echo "OpenJobStatus : STR : " . \persek_protocol\to_string( $obj ) . "\n";
}

function example_TemplateInfo()
{
    $obj = \persek_protocol\create_dummy__TemplateInfo();

    echo "TemplateInfo : STR : " . \persek_protocol\to_string( $obj ) . "\n";
}

function example_CancellationFailureReason()
{
    $obj = \persek_protocol\create_dummy__CancellationFailureReason();

    echo "CancellationFailureReason : STR : " . \persek_protocol\to_string( $obj ) . "\n";
}

function example_Action()
{
    $obj = \persek_protocol\create_dummy__Action();

    echo "Action : STR : " . \persek_protocol\to_string( $obj ) . "\n";
}

function example_ContactPhone()
{
    $obj = \persek_protocol\create_dummy__ContactPhone();

    echo "ContactPhone : STR : " . \persek_protocol\to_string( $obj ) . "\n";
}

function example_ContactPhoneWithId()
{
    $obj = \persek_protocol\create_dummy__ContactPhoneWithId();

    echo "ContactPhoneWithId : STR : " . \persek_protocol\to_string( $obj ) . "\n";
}

function example_Contact()
{
    $obj = \persek_protocol\create_dummy__Contact();

    echo "Contact : STR : " . \persek_protocol\to_string( $obj ) . "\n";
}

function example_ExtendedContactInfo()
{
    $obj = \persek_protocol\create_dummy__ExtendedContactInfo();

    echo "ExtendedContactInfo : STR : " . \persek_protocol\to_string( $obj ) . "\n";
}

function example_ReminderAction()
{
    $obj = \persek_protocol\create_dummy__ReminderAction();

    echo "ReminderAction : STR : " . \persek_protocol\to_string( $obj ) . "\n";
}

function example_ReminderOptions()
{
    $obj = \persek_protocol\create_dummy__ReminderOptions();

    echo "ReminderOptions : STR : " . \persek_protocol\to_string( $obj ) . "\n";
}

function example_Reminder()
{
    $obj = \persek_protocol\create_dummy__Reminder();

    echo "Reminder : STR : " . \persek_protocol\to_string( $obj ) . "\n";
}


# messages

function example_GetJobInfoRequest()
{
    $obj = \persek_protocol\create_dummy__GetJobInfoRequest();

    echo "GetJobInfoRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetJobInfoRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetJobInfoResponse()
{
    $obj = \persek_protocol\create_dummy__GetJobInfoResponse();

    echo "GetJobInfoResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetJobInfoResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetJobStatRequest()
{
    $obj = \persek_protocol\create_dummy__GetJobStatRequest();

    echo "GetJobStatRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetJobStatRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetJobStatResponse()
{
    $obj = \persek_protocol\create_dummy__GetJobStatResponse();

    echo "GetJobStatResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetJobStatResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_FindJobRequest()
{
    $obj = \persek_protocol\create_dummy__FindJobRequest();

    echo "FindJobRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "FindJobRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_FindJobResponse()
{
    $obj = \persek_protocol\create_dummy__FindJobResponse();

    echo "FindJobResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "FindJobResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_FindTemplatesRequest()
{
    $obj = \persek_protocol\create_dummy__FindTemplatesRequest();

    echo "FindTemplatesRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "FindTemplatesRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_FindTemplatesResponse()
{
    $obj = \persek_protocol\create_dummy__FindTemplatesResponse();

    echo "FindTemplatesResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "FindTemplatesResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_CancelJobRequest()
{
    $obj = \persek_protocol\create_dummy__CancelJobRequest();

    echo "CancelJobRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "CancelJobRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_CancelJobResponse()
{
    $obj = \persek_protocol\create_dummy__CancelJobResponse();

    echo "CancelJobResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "CancelJobResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_CancelJobsRequest()
{
    $obj = \persek_protocol\create_dummy__CancelJobsRequest();

    echo "CancelJobsRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "CancelJobsRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_CancelJobsResponse()
{
    $obj = \persek_protocol\create_dummy__CancelJobsResponse();

    echo "CancelJobsResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "CancelJobsResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_SayRequest()
{
    $obj = \persek_protocol\create_dummy__SayRequest();

    echo "SayRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "SayRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_SayResponse()
{
    $obj = \persek_protocol\create_dummy__SayResponse();

    echo "SayResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "SayResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_SayFeedbackRequest()
{
    $obj = \persek_protocol\create_dummy__SayFeedbackRequest();

    echo "SayFeedbackRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "SayFeedbackRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_SayFeedbackResponse()
{
    $obj = \persek_protocol\create_dummy__SayFeedbackResponse();

    echo "SayFeedbackResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "SayFeedbackResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_AddContactPhoneRequest()
{
    $obj = \persek_protocol\create_dummy__AddContactPhoneRequest();

    echo "AddContactPhoneRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "AddContactPhoneRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_AddContactPhoneResponse()
{
    $obj = \persek_protocol\create_dummy__AddContactPhoneResponse();

    echo "AddContactPhoneResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "AddContactPhoneResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_ModifyContactPhoneRequest()
{
    $obj = \persek_protocol\create_dummy__ModifyContactPhoneRequest();

    echo "ModifyContactPhoneRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "ModifyContactPhoneRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_ModifyContactPhoneResponse()
{
    $obj = \persek_protocol\create_dummy__ModifyContactPhoneResponse();

    echo "ModifyContactPhoneResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "ModifyContactPhoneResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_DeleteContactPhoneRequest()
{
    $obj = \persek_protocol\create_dummy__DeleteContactPhoneRequest();

    echo "DeleteContactPhoneRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "DeleteContactPhoneRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_DeleteContactPhoneResponse()
{
    $obj = \persek_protocol\create_dummy__DeleteContactPhoneResponse();

    echo "DeleteContactPhoneResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "DeleteContactPhoneResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetContactPhoneRequest()
{
    $obj = \persek_protocol\create_dummy__GetContactPhoneRequest();

    echo "GetContactPhoneRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetContactPhoneRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetContactPhoneResponse()
{
    $obj = \persek_protocol\create_dummy__GetContactPhoneResponse();

    echo "GetContactPhoneResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetContactPhoneResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_AddContactRequest()
{
    $obj = \persek_protocol\create_dummy__AddContactRequest();

    echo "AddContactRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "AddContactRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_AddContactResponse()
{
    $obj = \persek_protocol\create_dummy__AddContactResponse();

    echo "AddContactResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "AddContactResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_ModifyContactRequest()
{
    $obj = \persek_protocol\create_dummy__ModifyContactRequest();

    echo "ModifyContactRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "ModifyContactRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_ModifyContactResponse()
{
    $obj = \persek_protocol\create_dummy__ModifyContactResponse();

    echo "ModifyContactResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "ModifyContactResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_DeleteContactRequest()
{
    $obj = \persek_protocol\create_dummy__DeleteContactRequest();

    echo "DeleteContactRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "DeleteContactRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_DeleteContactResponse()
{
    $obj = \persek_protocol\create_dummy__DeleteContactResponse();

    echo "DeleteContactResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "DeleteContactResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetContactRequest()
{
    $obj = \persek_protocol\create_dummy__GetContactRequest();

    echo "GetContactRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetContactRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetContactResponse()
{
    $obj = \persek_protocol\create_dummy__GetContactResponse();

    echo "GetContactResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetContactResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetContactWithPhonesRequest()
{
    $obj = \persek_protocol\create_dummy__GetContactWithPhonesRequest();

    echo "GetContactWithPhonesRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetContactWithPhonesRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetContactWithPhonesResponse()
{
    $obj = \persek_protocol\create_dummy__GetContactWithPhonesResponse();

    echo "GetContactWithPhonesResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetContactWithPhonesResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetContactExtRequest()
{
    $obj = \persek_protocol\create_dummy__GetContactExtRequest();

    echo "GetContactExtRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetContactExtRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetContactExtResponse()
{
    $obj = \persek_protocol\create_dummy__GetContactExtResponse();

    echo "GetContactExtResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetContactExtResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetExtendedContactInfoRequest()
{
    $obj = \persek_protocol\create_dummy__GetExtendedContactInfoRequest();

    echo "GetExtendedContactInfoRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetExtendedContactInfoRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetExtendedContactInfoResponse()
{
    $obj = \persek_protocol\create_dummy__GetExtendedContactInfoResponse();

    echo "GetExtendedContactInfoResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetExtendedContactInfoResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_SetExtendedContactInfoRequest()
{
    $obj = \persek_protocol\create_dummy__SetExtendedContactInfoRequest();

    echo "SetExtendedContactInfoRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "SetExtendedContactInfoRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_SetExtendedContactInfoResponse()
{
    $obj = \persek_protocol\create_dummy__SetExtendedContactInfoResponse();

    echo "SetExtendedContactInfoResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "SetExtendedContactInfoResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_AddReminderRequest()
{
    $obj = \persek_protocol\create_dummy__AddReminderRequest();

    echo "AddReminderRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "AddReminderRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_AddReminderResponse()
{
    $obj = \persek_protocol\create_dummy__AddReminderResponse();

    echo "AddReminderResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "AddReminderResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_ModifyReminderRequest()
{
    $obj = \persek_protocol\create_dummy__ModifyReminderRequest();

    echo "ModifyReminderRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "ModifyReminderRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_ModifyReminderResponse()
{
    $obj = \persek_protocol\create_dummy__ModifyReminderResponse();

    echo "ModifyReminderResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "ModifyReminderResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetReminderRequest()
{
    $obj = \persek_protocol\create_dummy__GetReminderRequest();

    echo "GetReminderRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetReminderRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetReminderResponse()
{
    $obj = \persek_protocol\create_dummy__GetReminderResponse();

    echo "GetReminderResponse : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetReminderResponse : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetReminderStatusRequest()
{
    $obj = \persek_protocol\create_dummy__GetReminderStatusRequest();

    echo "GetReminderStatusRequest : STR : " . \persek_protocol\to_string( $obj ) . "\n";

    echo "GetReminderStatusRequest : REQ : " . \persek_protocol\to_generic_request( $obj ) . "\n";

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

# namespace_end persek_protocol


?>
