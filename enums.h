#ifndef APG_PERSEK_PROTOCOL__ENUMS_H
#define APG_PERSEK_PROTOCOL__ENUMS_H

namespace persek_protocol
{

enum class request_type_e
{
    UNDEF,
    GetJobInfoRequest,
    GetJobInfoResponse,
    GetJobStatRequest,
    GetJobStatResponse,
    FindJobRequest,
    FindJobResponse,
    FindTemplatesRequest,
    FindTemplatesResponse,
    CancelJobRequest,
    CancelJobResponse,
    CancelJobsRequest,
    CancelJobsResponse,
    SayRequest,
    SayResponse,
    SayFeedbackRequest,
    SayFeedbackResponse,
    AddContactPhoneRequest,
    AddContactPhoneResponse,
    ModifyContactPhoneRequest,
    ModifyContactPhoneResponse,
    DeleteContactPhoneRequest,
    DeleteContactPhoneResponse,
    GetContactPhoneRequest,
    GetContactPhoneResponse,
    AddContactRequest,
    AddContactResponse,
    ModifyContactRequest,
    ModifyContactResponse,
    DeleteContactRequest,
    DeleteContactResponse,
    GetContactRequest,
    GetContactResponse,
    GetContactWithPhonesRequest,
    GetContactWithPhonesResponse,
    GetContactExtRequest,
    GetContactExtResponse,
    GetExtendedContactInfoRequest,
    GetExtendedContactInfoResponse,
    SetExtendedContactInfoRequest,
    SetExtendedContactInfoResponse,
    AddReminderRequest,
    AddReminderResponse,
    ModifyReminderRequest,
    ModifyReminderResponse,
    GetReminderRequest,
    GetReminderResponse,
    GetReminderStatusRequest,
};

} // namespace persek_protocol

#endif // APG_PERSEK_PROTOCOL__ENUMS_H
