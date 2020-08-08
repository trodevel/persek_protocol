#include "protocol.h"
#include "str_helper.h"
#include "csv_helper.h"
#include "dummy_creator.h"
#include "validator.h"

#include <iostream>       // std::cout

template <class T>
void validate( const T & o, const std::string & name )
{
    try
    {
        persek_protocol::validator::validate( o );
        std::cout << name << " : valid" << std::endl;
    }
    catch( std::exception & e )
    {
        std::cout << name << " : invalid : " << e.what() << std::endl;
    }
}

// enums

void example_voice_e()
{
    auto obj = persek_protocol::dummy::create__voice_e();

    std::cout << "voice_e : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_urgency_e()
{
    auto obj = persek_protocol::dummy::create__urgency_e();

    std::cout << "urgency_e : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_JobInfo_type_e()
{
    auto obj = persek_protocol::dummy::create__JobInfo_type_e();

    std::cout << "JobInfo_type_e : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_exit_status_e()
{
    auto obj = persek_protocol::dummy::create__exit_status_e();

    std::cout << "exit_status_e : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_OpenJobStatus_state_e()
{
    auto obj = persek_protocol::dummy::create__OpenJobStatus_state_e();

    std::cout << "OpenJobStatus_state_e : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_FindJobRequest_status_e()
{
    auto obj = persek_protocol::dummy::create__FindJobRequest_status_e();

    std::cout << "FindJobRequest_status_e : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_action_type_e()
{
    auto obj = persek_protocol::dummy::create__action_type_e();

    std::cout << "action_type_e : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_ContactPhone_type_e()
{
    auto obj = persek_protocol::dummy::create__ContactPhone_type_e();

    std::cout << "ContactPhone_type_e : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_gender_e()
{
    auto obj = persek_protocol::dummy::create__gender_e();

    std::cout << "gender_e : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_ReminderAction_type_e()
{
    auto obj = persek_protocol::dummy::create__ReminderAction_type_e();

    std::cout << "ReminderAction_type_e : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}


// objects

void example_JobOptions()
{
    auto obj = persek_protocol::dummy::create__JobOptions();

    std::cout << "JobOptions : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_JobInfo()
{
    auto obj = persek_protocol::dummy::create__JobInfo();

    std::cout << "JobInfo : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_ClosedJobStatus()
{
    auto obj = persek_protocol::dummy::create__ClosedJobStatus();

    std::cout << "ClosedJobStatus : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_OpenJobStatus()
{
    auto obj = persek_protocol::dummy::create__OpenJobStatus();

    std::cout << "OpenJobStatus : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_TemplateInfo()
{
    auto obj = persek_protocol::dummy::create__TemplateInfo();

    std::cout << "TemplateInfo : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_CancellationFailureReason()
{
    auto obj = persek_protocol::dummy::create__CancellationFailureReason();

    std::cout << "CancellationFailureReason : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_Action()
{
    auto obj = persek_protocol::dummy::create__Action();

    std::cout << "Action : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_ContactPhone()
{
    auto obj = persek_protocol::dummy::create__ContactPhone();

    std::cout << "ContactPhone : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_ContactPhoneWithId()
{
    auto obj = persek_protocol::dummy::create__ContactPhoneWithId();

    std::cout << "ContactPhoneWithId : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_Contact()
{
    auto obj = persek_protocol::dummy::create__Contact();

    std::cout << "Contact : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_ExtendedContactInfo()
{
    auto obj = persek_protocol::dummy::create__ExtendedContactInfo();

    std::cout << "ExtendedContactInfo : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_ReminderAction()
{
    auto obj = persek_protocol::dummy::create__ReminderAction();

    std::cout << "ReminderAction : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_ReminderOptions()
{
    auto obj = persek_protocol::dummy::create__ReminderOptions();

    std::cout << "ReminderOptions : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_Reminder()
{
    auto obj = persek_protocol::dummy::create__Reminder();

    std::cout << "Reminder : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;
}


// messages

void example_GetJobInfoRequest()
{
    auto & obj = * persek_protocol::dummy::create__GetJobInfoRequest();

    std::cout << "GetJobInfoRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetJobInfoRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetJobInfoRequest" );

    delete & obj;
}

void example_GetJobInfoResponse()
{
    auto & obj = * persek_protocol::dummy::create__GetJobInfoResponse();

    std::cout << "GetJobInfoResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetJobInfoResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetJobInfoResponse" );

    delete & obj;
}

void example_GetJobStatRequest()
{
    auto & obj = * persek_protocol::dummy::create__GetJobStatRequest();

    std::cout << "GetJobStatRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetJobStatRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetJobStatRequest" );

    delete & obj;
}

void example_GetJobStatResponse()
{
    auto & obj = * persek_protocol::dummy::create__GetJobStatResponse();

    std::cout << "GetJobStatResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetJobStatResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetJobStatResponse" );

    delete & obj;
}

void example_FindJobRequest()
{
    auto & obj = * persek_protocol::dummy::create__FindJobRequest();

    std::cout << "FindJobRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "FindJobRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "FindJobRequest" );

    delete & obj;
}

void example_FindJobResponse()
{
    auto & obj = * persek_protocol::dummy::create__FindJobResponse();

    std::cout << "FindJobResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "FindJobResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "FindJobResponse" );

    delete & obj;
}

void example_FindTemplatesRequest()
{
    auto & obj = * persek_protocol::dummy::create__FindTemplatesRequest();

    std::cout << "FindTemplatesRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "FindTemplatesRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "FindTemplatesRequest" );

    delete & obj;
}

void example_FindTemplatesResponse()
{
    auto & obj = * persek_protocol::dummy::create__FindTemplatesResponse();

    std::cout << "FindTemplatesResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "FindTemplatesResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "FindTemplatesResponse" );

    delete & obj;
}

void example_CancelJobRequest()
{
    auto & obj = * persek_protocol::dummy::create__CancelJobRequest();

    std::cout << "CancelJobRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "CancelJobRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "CancelJobRequest" );

    delete & obj;
}

void example_CancelJobResponse()
{
    auto & obj = * persek_protocol::dummy::create__CancelJobResponse();

    std::cout << "CancelJobResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "CancelJobResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "CancelJobResponse" );

    delete & obj;
}

void example_CancelJobsRequest()
{
    auto & obj = * persek_protocol::dummy::create__CancelJobsRequest();

    std::cout << "CancelJobsRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "CancelJobsRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "CancelJobsRequest" );

    delete & obj;
}

void example_CancelJobsResponse()
{
    auto & obj = * persek_protocol::dummy::create__CancelJobsResponse();

    std::cout << "CancelJobsResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "CancelJobsResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "CancelJobsResponse" );

    delete & obj;
}

void example_SayRequest()
{
    auto & obj = * persek_protocol::dummy::create__SayRequest();

    std::cout << "SayRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "SayRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "SayRequest" );

    delete & obj;
}

void example_SayResponse()
{
    auto & obj = * persek_protocol::dummy::create__SayResponse();

    std::cout << "SayResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "SayResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "SayResponse" );

    delete & obj;
}

void example_SayFeedbackRequest()
{
    auto & obj = * persek_protocol::dummy::create__SayFeedbackRequest();

    std::cout << "SayFeedbackRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "SayFeedbackRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "SayFeedbackRequest" );

    delete & obj;
}

void example_SayFeedbackResponse()
{
    auto & obj = * persek_protocol::dummy::create__SayFeedbackResponse();

    std::cout << "SayFeedbackResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "SayFeedbackResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "SayFeedbackResponse" );

    delete & obj;
}

void example_AddContactPhoneRequest()
{
    auto & obj = * persek_protocol::dummy::create__AddContactPhoneRequest();

    std::cout << "AddContactPhoneRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AddContactPhoneRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AddContactPhoneRequest" );

    delete & obj;
}

void example_AddContactPhoneResponse()
{
    auto & obj = * persek_protocol::dummy::create__AddContactPhoneResponse();

    std::cout << "AddContactPhoneResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AddContactPhoneResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AddContactPhoneResponse" );

    delete & obj;
}

void example_ModifyContactPhoneRequest()
{
    auto & obj = * persek_protocol::dummy::create__ModifyContactPhoneRequest();

    std::cout << "ModifyContactPhoneRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "ModifyContactPhoneRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "ModifyContactPhoneRequest" );

    delete & obj;
}

void example_ModifyContactPhoneResponse()
{
    auto & obj = * persek_protocol::dummy::create__ModifyContactPhoneResponse();

    std::cout << "ModifyContactPhoneResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "ModifyContactPhoneResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "ModifyContactPhoneResponse" );

    delete & obj;
}

void example_DeleteContactPhoneRequest()
{
    auto & obj = * persek_protocol::dummy::create__DeleteContactPhoneRequest();

    std::cout << "DeleteContactPhoneRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "DeleteContactPhoneRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "DeleteContactPhoneRequest" );

    delete & obj;
}

void example_DeleteContactPhoneResponse()
{
    auto & obj = * persek_protocol::dummy::create__DeleteContactPhoneResponse();

    std::cout << "DeleteContactPhoneResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "DeleteContactPhoneResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "DeleteContactPhoneResponse" );

    delete & obj;
}

void example_GetContactPhoneRequest()
{
    auto & obj = * persek_protocol::dummy::create__GetContactPhoneRequest();

    std::cout << "GetContactPhoneRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetContactPhoneRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetContactPhoneRequest" );

    delete & obj;
}

void example_GetContactPhoneResponse()
{
    auto & obj = * persek_protocol::dummy::create__GetContactPhoneResponse();

    std::cout << "GetContactPhoneResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetContactPhoneResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetContactPhoneResponse" );

    delete & obj;
}

void example_AddContactRequest()
{
    auto & obj = * persek_protocol::dummy::create__AddContactRequest();

    std::cout << "AddContactRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AddContactRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AddContactRequest" );

    delete & obj;
}

void example_AddContactResponse()
{
    auto & obj = * persek_protocol::dummy::create__AddContactResponse();

    std::cout << "AddContactResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AddContactResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AddContactResponse" );

    delete & obj;
}

void example_ModifyContactRequest()
{
    auto & obj = * persek_protocol::dummy::create__ModifyContactRequest();

    std::cout << "ModifyContactRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "ModifyContactRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "ModifyContactRequest" );

    delete & obj;
}

void example_ModifyContactResponse()
{
    auto & obj = * persek_protocol::dummy::create__ModifyContactResponse();

    std::cout << "ModifyContactResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "ModifyContactResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "ModifyContactResponse" );

    delete & obj;
}

void example_DeleteContactRequest()
{
    auto & obj = * persek_protocol::dummy::create__DeleteContactRequest();

    std::cout << "DeleteContactRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "DeleteContactRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "DeleteContactRequest" );

    delete & obj;
}

void example_DeleteContactResponse()
{
    auto & obj = * persek_protocol::dummy::create__DeleteContactResponse();

    std::cout << "DeleteContactResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "DeleteContactResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "DeleteContactResponse" );

    delete & obj;
}

void example_GetContactRequest()
{
    auto & obj = * persek_protocol::dummy::create__GetContactRequest();

    std::cout << "GetContactRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetContactRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetContactRequest" );

    delete & obj;
}

void example_GetContactResponse()
{
    auto & obj = * persek_protocol::dummy::create__GetContactResponse();

    std::cout << "GetContactResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetContactResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetContactResponse" );

    delete & obj;
}

void example_GetContactWithPhonesRequest()
{
    auto & obj = * persek_protocol::dummy::create__GetContactWithPhonesRequest();

    std::cout << "GetContactWithPhonesRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetContactWithPhonesRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetContactWithPhonesRequest" );

    delete & obj;
}

void example_GetContactWithPhonesResponse()
{
    auto & obj = * persek_protocol::dummy::create__GetContactWithPhonesResponse();

    std::cout << "GetContactWithPhonesResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetContactWithPhonesResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetContactWithPhonesResponse" );

    delete & obj;
}

void example_GetContactExtRequest()
{
    auto & obj = * persek_protocol::dummy::create__GetContactExtRequest();

    std::cout << "GetContactExtRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetContactExtRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetContactExtRequest" );

    delete & obj;
}

void example_GetContactExtResponse()
{
    auto & obj = * persek_protocol::dummy::create__GetContactExtResponse();

    std::cout << "GetContactExtResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetContactExtResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetContactExtResponse" );

    delete & obj;
}

void example_GetExtendedContactInfoRequest()
{
    auto & obj = * persek_protocol::dummy::create__GetExtendedContactInfoRequest();

    std::cout << "GetExtendedContactInfoRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetExtendedContactInfoRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetExtendedContactInfoRequest" );

    delete & obj;
}

void example_GetExtendedContactInfoResponse()
{
    auto & obj = * persek_protocol::dummy::create__GetExtendedContactInfoResponse();

    std::cout << "GetExtendedContactInfoResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetExtendedContactInfoResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetExtendedContactInfoResponse" );

    delete & obj;
}

void example_SetExtendedContactInfoRequest()
{
    auto & obj = * persek_protocol::dummy::create__SetExtendedContactInfoRequest();

    std::cout << "SetExtendedContactInfoRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "SetExtendedContactInfoRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "SetExtendedContactInfoRequest" );

    delete & obj;
}

void example_SetExtendedContactInfoResponse()
{
    auto & obj = * persek_protocol::dummy::create__SetExtendedContactInfoResponse();

    std::cout << "SetExtendedContactInfoResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "SetExtendedContactInfoResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "SetExtendedContactInfoResponse" );

    delete & obj;
}

void example_AddReminderRequest()
{
    auto & obj = * persek_protocol::dummy::create__AddReminderRequest();

    std::cout << "AddReminderRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AddReminderRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AddReminderRequest" );

    delete & obj;
}

void example_AddReminderResponse()
{
    auto & obj = * persek_protocol::dummy::create__AddReminderResponse();

    std::cout << "AddReminderResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AddReminderResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AddReminderResponse" );

    delete & obj;
}

void example_ModifyReminderRequest()
{
    auto & obj = * persek_protocol::dummy::create__ModifyReminderRequest();

    std::cout << "ModifyReminderRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "ModifyReminderRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "ModifyReminderRequest" );

    delete & obj;
}

void example_ModifyReminderResponse()
{
    auto & obj = * persek_protocol::dummy::create__ModifyReminderResponse();

    std::cout << "ModifyReminderResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "ModifyReminderResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "ModifyReminderResponse" );

    delete & obj;
}

void example_GetReminderRequest()
{
    auto & obj = * persek_protocol::dummy::create__GetReminderRequest();

    std::cout << "GetReminderRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetReminderRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetReminderRequest" );

    delete & obj;
}

void example_GetReminderResponse()
{
    auto & obj = * persek_protocol::dummy::create__GetReminderResponse();

    std::cout << "GetReminderResponse : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetReminderResponse : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetReminderResponse" );

    delete & obj;
}

void example_GetReminderStatusRequest()
{
    auto & obj = * persek_protocol::dummy::create__GetReminderStatusRequest();

    std::cout << "GetReminderStatusRequest : STR : " << persek_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetReminderStatusRequest : CSV : " << persek_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetReminderStatusRequest" );

    delete & obj;
}


int main( int argc, char ** argv )
{
    if( argc > 1 )
    {
        std::srand( std::stoi( std::string( argv[1] ) ) );
    }

    // enums

    example_voice_e();
    example_urgency_e();
    example_JobInfo_type_e();
    example_exit_status_e();
    example_OpenJobStatus_state_e();
    example_FindJobRequest_status_e();
    example_action_type_e();
    example_ContactPhone_type_e();
    example_gender_e();
    example_ReminderAction_type_e();

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

    return 0;
}

