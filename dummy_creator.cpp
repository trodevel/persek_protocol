// includes
#include "dummy_creator.h"
#include "generic_protocol/dummy_creator.h"
#include "basic_parser/dummy_creator.h"
#include "basic_objects/dummy_creator.h"
#include "dtmf_tools_protocol/dummy_creator.h"
#include "lang_tools_protocol/dummy_creator.h"
#include "object_initializer.h"

namespace persek_protocol
{

namespace dummy
{

// enums

voice_e create__voice_e()
{
    static const unsigned SIZE = 3;

    static const voice_e values[SIZE] = { voice_e::UNDEF, voice_e::MALE_A, voice_e::FEMALE_A,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

urgency_e create__urgency_e()
{
    static const unsigned SIZE = 3;

    static const urgency_e values[SIZE] = { urgency_e::UNDEF, urgency_e::IMMEDIATE, urgency_e::TIMED,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

JobInfo_type_e create__JobInfo_type_e()
{
    static const unsigned SIZE = 5;

    static const JobInfo_type_e values[SIZE] = { JobInfo_type_e::UNDEF, JobInfo_type_e::SAY, JobInfo_type_e::SAY_FEEDBACK, JobInfo_type_e::FSM, JobInfo_type_e::REMINDER,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

exit_status_e create__exit_status_e()
{
    static const unsigned SIZE = 5;

    static const exit_status_e values[SIZE] = { exit_status_e::DONE, exit_status_e::CANCELLED, exit_status_e::FAILED, exit_status_e::REFUSED_BY_RECIPIENT, exit_status_e::ABORTED_BY_RECIPIENT,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

OpenJobStatus_state_e create__OpenJobStatus_state_e()
{
    static const unsigned SIZE = 8;

    static const OpenJobStatus_state_e values[SIZE] = { OpenJobStatus_state_e::IDLE, OpenJobStatus_state_e::WAITING_PROC_STARTED, OpenJobStatus_state_e::ACTIVE, OpenJobStatus_state_e::WRONG_ACTIVE, OpenJobStatus_state_e::CANCELLED_IN_A, OpenJobStatus_state_e::CANCELLED_IN_WPS, OpenJobStatus_state_e::COMPLETED, OpenJobStatus_state_e::WAITING_REDIAL_TIMER,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

FindJobRequest_status_e create__FindJobRequest_status_e()
{
    static const unsigned SIZE = 3;

    static const FindJobRequest_status_e values[SIZE] = { FindJobRequest_status_e::ANY, FindJobRequest_status_e::OPEN, FindJobRequest_status_e::CLOSED,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

action_type_e create__action_type_e()
{
    static const unsigned SIZE = 3;

    static const action_type_e values[SIZE] = { action_type_e::NONE, action_type_e::REPEAT, action_type_e::DROP,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

ContactPhone_type_e create__ContactPhone_type_e()
{
    static const unsigned SIZE = 3;

    static const ContactPhone_type_e values[SIZE] = { ContactPhone_type_e::DFLT, ContactPhone_type_e::LANDLINE, ContactPhone_type_e::MOBILE,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

gender_e create__gender_e()
{
    static const unsigned SIZE = 3;

    static const gender_e values[SIZE] = { gender_e::UNDEF, gender_e::MALE, gender_e::FEMALE,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

ReminderAction_type_e create__ReminderAction_type_e()
{
    static const unsigned SIZE = 4;

    static const ReminderAction_type_e values[SIZE] = { ReminderAction_type_e::NONE, ReminderAction_type_e::REPEAT, ReminderAction_type_e::DROP_FEEDBACK, ReminderAction_type_e::DROP_SNOOZE,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

// objects

JobOptions create__JobOptions()
{
    JobOptions res;

    ::persek_protocol::initialize( & res
        , dummy::create__voice_e()
        , dummy::create__urgency_e()
        , ::lang_tools::dummy::create__lang_e()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__bool()
        , ::basic_objects::dummy::create__TimeWindow()
        , ::basic_objects::dummy::create__Weekdays()
        );

    return res;
}

JobInfo create__JobInfo()
{
    JobInfo res;

    ::persek_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__JobInfo_type_e()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__JobOptions()
        );

    return res;
}

ClosedJobStatus create__ClosedJobStatus()
{
    ClosedJobStatus res;

    ::persek_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__exit_status_e()
        , ::basic_parser::dummy::create__vector_t<uint32_t, uint32_t(*)()>( & ::basic_parser::dummy::create__uint32 ) // Array
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

OpenJobStatus create__OpenJobStatus()
{
    OpenJobStatus res;

    ::persek_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__OpenJobStatus_state_e()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

TemplateInfo create__TemplateInfo()
{
    TemplateInfo res;

    ::persek_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__string()
        , ::lang_tools::dummy::create__lang_e()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__vector_t<std::string, std::string(*)()>( & ::basic_parser::dummy::create__string ) // Array
        );

    return res;
}

CancellationFailureReason create__CancellationFailureReason()
{
    CancellationFailureReason res;

    ::persek_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , ::generic_protocol::dummy::create__ErrorResponse_type_e()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

Action create__Action()
{
    Action res;

    ::persek_protocol::initialize( & res
        , dummy::create__action_type_e()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

ContactPhone create__ContactPhone()
{
    ContactPhone res;

    ::persek_protocol::initialize( & res
        , dummy::create__ContactPhone_type_e()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

ContactPhoneWithId create__ContactPhoneWithId()
{
    ContactPhoneWithId res;

    ::persek_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__ContactPhone()
        );

    return res;
}

Contact create__Contact()
{
    Contact res;

    ::persek_protocol::initialize( & res
        , dummy::create__gender_e()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_objects::dummy::create__Date()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

ExtendedContactInfo create__ExtendedContactInfo()
{
    ExtendedContactInfo res;

    ::persek_protocol::initialize( & res
        , dummy::create__voice_e()
        , ::lang_tools::dummy::create__lang_e()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__bool()
        , ::basic_objects::dummy::create__TimeWindow()
        , ::basic_objects::dummy::create__Weekdays()
        );

    return res;
}

ReminderAction create__ReminderAction()
{
    ReminderAction res;

    ::persek_protocol::initialize( & res
        , dummy::create__ReminderAction_type_e()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

ReminderOptions create__ReminderOptions()
{
    ReminderOptions res;

    ::persek_protocol::initialize( & res
        , dummy::create__voice_e()
        , ::lang_tools::dummy::create__lang_e()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__bool()
        , ::basic_objects::dummy::create__TimeWindow()
        , ::basic_objects::dummy::create__Weekdays()
        );

    return res;
}

Reminder create__Reminder()
{
    Reminder res;

    ::persek_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__map_t<std::string, std::string, std::string(*)(), std::string(*)()>( & ::basic_parser::dummy::create__string, & ::basic_parser::dummy::create__string ) // Map
        , ::basic_parser::dummy::create__map_t<dtmf_tools::tone_e, ReminderAction, dtmf_tools::tone_e(*)(), ReminderAction(*)()>( & ::dtmf_tools::dummy::create__tone_e, & dummy::create__ReminderAction ) // Map
        , dummy::create__ReminderOptions()
        );

    return res;
}

// messages

GetJobInfoRequest * create__GetJobInfoRequest()
{
    auto res = new GetJobInfoRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__vector_t<uint32_t, uint32_t(*)()>( & ::basic_parser::dummy::create__uint32 ) // Array
        );

    return res;
}

GetJobInfoResponse * create__GetJobInfoResponse()
{
    auto res = new GetJobInfoResponse;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__vector_t<JobInfo, JobInfo(*)()>( & dummy::create__JobInfo ) // Array
        );

    return res;
}

GetJobStatRequest * create__GetJobStatRequest()
{
    auto res = new GetJobStatRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__vector_t<uint32_t, uint32_t(*)()>( & ::basic_parser::dummy::create__uint32 ) // Array
        );

    return res;
}

GetJobStatResponse * create__GetJobStatResponse()
{
    auto res = new GetJobStatResponse;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__vector_t<OpenJobStatus, OpenJobStatus(*)()>( & dummy::create__OpenJobStatus ) // Array
        , ::basic_parser::dummy::create__vector_t<ClosedJobStatus, ClosedJobStatus(*)()>( & dummy::create__ClosedJobStatus ) // Array
        );

    return res;
}

FindJobRequest * create__FindJobRequest()
{
    auto res = new FindJobRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__FindJobRequest_status_e()
        , ::basic_parser::dummy::create__string()
        , ::basic_objects::dummy::create__TimeRange()
        , ::basic_objects::dummy::create__TimeRange()
        , ::basic_objects::dummy::create__TimeRange()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

FindJobResponse * create__FindJobResponse()
{
    auto res = new FindJobResponse;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__vector_t<uint32_t, uint32_t(*)()>( & ::basic_parser::dummy::create__uint32 ) // Array
        );

    return res;
}

FindTemplatesRequest * create__FindTemplatesRequest()
{
    auto res = new FindTemplatesRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__string()
        , ::lang_tools::dummy::create__lang_e()
        );

    return res;
}

FindTemplatesResponse * create__FindTemplatesResponse()
{
    auto res = new FindTemplatesResponse;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__vector_t<TemplateInfo, TemplateInfo(*)()>( & dummy::create__TemplateInfo ) // Array
        );

    return res;
}

CancelJobRequest * create__CancelJobRequest()
{
    auto res = new CancelJobRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

CancelJobResponse * create__CancelJobResponse()
{
    auto res = new CancelJobResponse;

    ::persek_protocol::initialize( res
        );

    return res;
}

CancelJobsRequest * create__CancelJobsRequest()
{
    auto res = new CancelJobsRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__vector_t<uint32_t, uint32_t(*)()>( & ::basic_parser::dummy::create__uint32 ) // Array
        );

    return res;
}

CancelJobsResponse * create__CancelJobsResponse()
{
    auto res = new CancelJobsResponse;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__vector_t<uint32_t, uint32_t(*)()>( & ::basic_parser::dummy::create__uint32 ) // Array
        , ::basic_parser::dummy::create__vector_t<CancellationFailureReason, CancellationFailureReason(*)()>( & dummy::create__CancellationFailureReason ) // Array
        );

    return res;
}

SayRequest * create__SayRequest()
{
    auto res = new SayRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__map_t<std::string, std::string, std::string(*)(), std::string(*)()>( & ::basic_parser::dummy::create__string, & ::basic_parser::dummy::create__string ) // Map
        , dummy::create__JobOptions()
        );

    return res;
}

SayResponse * create__SayResponse()
{
    auto res = new SayResponse;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

SayFeedbackRequest * create__SayFeedbackRequest()
{
    auto res = new SayFeedbackRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__map_t<std::string, std::string, std::string(*)(), std::string(*)()>( & ::basic_parser::dummy::create__string, & ::basic_parser::dummy::create__string ) // Map
        , ::basic_parser::dummy::create__map_t<dtmf_tools::tone_e, Action, dtmf_tools::tone_e(*)(), Action(*)()>( & ::dtmf_tools::dummy::create__tone_e, & dummy::create__Action ) // Map
        , dummy::create__JobOptions()
        );

    return res;
}

SayFeedbackResponse * create__SayFeedbackResponse()
{
    auto res = new SayFeedbackResponse;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

AddContactPhoneRequest * create__AddContactPhoneRequest()
{
    auto res = new AddContactPhoneRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__ContactPhone()
        );

    return res;
}

AddContactPhoneResponse * create__AddContactPhoneResponse()
{
    auto res = new AddContactPhoneResponse;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

ModifyContactPhoneRequest * create__ModifyContactPhoneRequest()
{
    auto res = new ModifyContactPhoneRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__ContactPhone()
        );

    return res;
}

ModifyContactPhoneResponse * create__ModifyContactPhoneResponse()
{
    auto res = new ModifyContactPhoneResponse;

    ::persek_protocol::initialize( res
        );

    return res;
}

DeleteContactPhoneRequest * create__DeleteContactPhoneRequest()
{
    auto res = new DeleteContactPhoneRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

DeleteContactPhoneResponse * create__DeleteContactPhoneResponse()
{
    auto res = new DeleteContactPhoneResponse;

    ::persek_protocol::initialize( res
        );

    return res;
}

GetContactPhoneRequest * create__GetContactPhoneRequest()
{
    auto res = new GetContactPhoneRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

GetContactPhoneResponse * create__GetContactPhoneResponse()
{
    auto res = new GetContactPhoneResponse;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__ContactPhone()
        );

    return res;
}

AddContactRequest * create__AddContactRequest()
{
    auto res = new AddContactRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__Contact()
        );

    return res;
}

AddContactResponse * create__AddContactResponse()
{
    auto res = new AddContactResponse;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

ModifyContactRequest * create__ModifyContactRequest()
{
    auto res = new ModifyContactRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__Contact()
        );

    return res;
}

ModifyContactResponse * create__ModifyContactResponse()
{
    auto res = new ModifyContactResponse;

    ::persek_protocol::initialize( res
        );

    return res;
}

DeleteContactRequest * create__DeleteContactRequest()
{
    auto res = new DeleteContactRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

DeleteContactResponse * create__DeleteContactResponse()
{
    auto res = new DeleteContactResponse;

    ::persek_protocol::initialize( res
        );

    return res;
}

GetContactRequest * create__GetContactRequest()
{
    auto res = new GetContactRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

GetContactResponse * create__GetContactResponse()
{
    auto res = new GetContactResponse;

    ::persek_protocol::initialize( res
        , dummy::create__Contact()
        , ::basic_parser::dummy::create__vector_t<uint32_t, uint32_t(*)()>( & ::basic_parser::dummy::create__uint32 ) // Array
        );

    return res;
}

GetContactWithPhonesRequest * create__GetContactWithPhonesRequest()
{
    auto res = new GetContactWithPhonesRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

GetContactWithPhonesResponse * create__GetContactWithPhonesResponse()
{
    auto res = new GetContactWithPhonesResponse;

    ::persek_protocol::initialize( res
        , dummy::create__Contact()
        , ::basic_parser::dummy::create__vector_t<ContactPhoneWithId, ContactPhoneWithId(*)()>( & dummy::create__ContactPhoneWithId ) // Array
        );

    return res;
}

GetContactExtRequest * create__GetContactExtRequest()
{
    auto res = new GetContactExtRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

GetContactExtResponse * create__GetContactExtResponse()
{
    auto res = new GetContactExtResponse;

    ::persek_protocol::initialize( res
        , dummy::create__Contact()
        , ::basic_parser::dummy::create__vector_t<ContactPhoneWithId, ContactPhoneWithId(*)()>( & dummy::create__ContactPhoneWithId ) // Array
        , dummy::create__ExtendedContactInfo()
        );

    return res;
}

GetExtendedContactInfoRequest * create__GetExtendedContactInfoRequest()
{
    auto res = new GetExtendedContactInfoRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

GetExtendedContactInfoResponse * create__GetExtendedContactInfoResponse()
{
    auto res = new GetExtendedContactInfoResponse;

    ::persek_protocol::initialize( res
        , dummy::create__ExtendedContactInfo()
        );

    return res;
}

SetExtendedContactInfoRequest * create__SetExtendedContactInfoRequest()
{
    auto res = new SetExtendedContactInfoRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__ExtendedContactInfo()
        );

    return res;
}

SetExtendedContactInfoResponse * create__SetExtendedContactInfoResponse()
{
    auto res = new SetExtendedContactInfoResponse;

    ::persek_protocol::initialize( res
        );

    return res;
}

AddReminderRequest * create__AddReminderRequest()
{
    auto res = new AddReminderRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__Reminder()
        );

    return res;
}

AddReminderResponse * create__AddReminderResponse()
{
    auto res = new AddReminderResponse;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

ModifyReminderRequest * create__ModifyReminderRequest()
{
    auto res = new ModifyReminderRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__Reminder()
        );

    return res;
}

ModifyReminderResponse * create__ModifyReminderResponse()
{
    auto res = new ModifyReminderResponse;

    ::persek_protocol::initialize( res
        );

    return res;
}

GetReminderRequest * create__GetReminderRequest()
{
    auto res = new GetReminderRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

GetReminderResponse * create__GetReminderResponse()
{
    auto res = new GetReminderResponse;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__string()
        , dummy::create__Reminder()
        );

    return res;
}

GetReminderStatusRequest * create__GetReminderStatusRequest()
{
    auto res = new GetReminderStatusRequest;

    ::persek_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__string()
        , ::basic_objects::dummy::create__TimeRange()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

} // namespace dummy

} // namespace persek_protocol

