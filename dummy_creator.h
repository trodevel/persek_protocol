#ifndef APG_PERSEK_PROTOCOL__DUMMY_CREATOR_H
#define APG_PERSEK_PROTOCOL__DUMMY_CREATOR_H

// includes
#include "protocol.h"

namespace persek_protocol
{

namespace dummy
{

// enums

voice_e create__voice_e();
urgency_e create__urgency_e();
JobInfo_type_e create__JobInfo_type_e();
exit_status_e create__exit_status_e();
OpenJobStatus_state_e create__OpenJobStatus_state_e();
FindJobRequest_status_e create__FindJobRequest_status_e();
action_type_e create__action_type_e();
ContactPhone_type_e create__ContactPhone_type_e();
gender_e create__gender_e();
ReminderAction_type_e create__ReminderAction_type_e();

// objects

JobOptions create__JobOptions();
JobInfo create__JobInfo();
ClosedJobStatus create__ClosedJobStatus();
OpenJobStatus create__OpenJobStatus();
TemplateInfo create__TemplateInfo();
CancellationFailureReason create__CancellationFailureReason();
Action create__Action();
ContactPhone create__ContactPhone();
ContactPhoneWithId create__ContactPhoneWithId();
Contact create__Contact();
ExtendedContactInfo create__ExtendedContactInfo();
ReminderAction create__ReminderAction();
ReminderOptions create__ReminderOptions();
Reminder create__Reminder();

// messages

GetJobInfoRequest * create__GetJobInfoRequest();
GetJobInfoResponse * create__GetJobInfoResponse();
GetJobStatRequest * create__GetJobStatRequest();
GetJobStatResponse * create__GetJobStatResponse();
FindJobRequest * create__FindJobRequest();
FindJobResponse * create__FindJobResponse();
FindTemplatesRequest * create__FindTemplatesRequest();
FindTemplatesResponse * create__FindTemplatesResponse();
CancelJobRequest * create__CancelJobRequest();
CancelJobResponse * create__CancelJobResponse();
CancelJobsRequest * create__CancelJobsRequest();
CancelJobsResponse * create__CancelJobsResponse();
SayRequest * create__SayRequest();
SayResponse * create__SayResponse();
SayFeedbackRequest * create__SayFeedbackRequest();
SayFeedbackResponse * create__SayFeedbackResponse();
AddContactPhoneRequest * create__AddContactPhoneRequest();
AddContactPhoneResponse * create__AddContactPhoneResponse();
ModifyContactPhoneRequest * create__ModifyContactPhoneRequest();
ModifyContactPhoneResponse * create__ModifyContactPhoneResponse();
DeleteContactPhoneRequest * create__DeleteContactPhoneRequest();
DeleteContactPhoneResponse * create__DeleteContactPhoneResponse();
GetContactPhoneRequest * create__GetContactPhoneRequest();
GetContactPhoneResponse * create__GetContactPhoneResponse();
AddContactRequest * create__AddContactRequest();
AddContactResponse * create__AddContactResponse();
ModifyContactRequest * create__ModifyContactRequest();
ModifyContactResponse * create__ModifyContactResponse();
DeleteContactRequest * create__DeleteContactRequest();
DeleteContactResponse * create__DeleteContactResponse();
GetContactRequest * create__GetContactRequest();
GetContactResponse * create__GetContactResponse();
GetContactWithPhonesRequest * create__GetContactWithPhonesRequest();
GetContactWithPhonesResponse * create__GetContactWithPhonesResponse();
GetContactExtRequest * create__GetContactExtRequest();
GetContactExtResponse * create__GetContactExtResponse();
GetExtendedContactInfoRequest * create__GetExtendedContactInfoRequest();
GetExtendedContactInfoResponse * create__GetExtendedContactInfoResponse();
SetExtendedContactInfoRequest * create__SetExtendedContactInfoRequest();
SetExtendedContactInfoResponse * create__SetExtendedContactInfoResponse();
AddReminderRequest * create__AddReminderRequest();
AddReminderResponse * create__AddReminderResponse();
ModifyReminderRequest * create__ModifyReminderRequest();
ModifyReminderResponse * create__ModifyReminderResponse();
GetReminderRequest * create__GetReminderRequest();
GetReminderResponse * create__GetReminderResponse();
GetReminderStatusRequest * create__GetReminderStatusRequest();

} // namespace dummy

} // namespace persek_protocol

#endif // APG_PERSEK_PROTOCOL__DUMMY_CREATOR_H
