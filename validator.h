#ifndef APG_PERSEK__VALIDATOR_H
#define APG_PERSEK__VALIDATOR_H

// includes
#include "protocol.h"

namespace persek_protocol
{

namespace validator
{

// enums
bool validate( const std::string & prefix, const voice_e r );
bool validate( const std::string & prefix, const urgency_e r );
bool validate( const std::string & prefix, const JobInfo_type_e r );
bool validate( const std::string & prefix, const exit_status_e r );
bool validate( const std::string & prefix, const OpenJobStatus_state_e r );
bool validate( const std::string & prefix, const FindJobRequest_status_e r );
bool validate( const std::string & prefix, const action_type_e r );
bool validate( const std::string & prefix, const ContactPhone_type_e r );
bool validate( const std::string & prefix, const gender_e r );
bool validate( const std::string & prefix, const ReminderAction_type_e r );

// objects
bool validate( const std::string & prefix, const JobOptions & r );
bool validate( const std::string & prefix, const JobInfo & r );
bool validate( const std::string & prefix, const ClosedJobStatus & r );
bool validate( const std::string & prefix, const OpenJobStatus & r );
bool validate( const std::string & prefix, const TemplateInfo & r );
bool validate( const std::string & prefix, const CancellationFailureReason & r );
bool validate( const std::string & prefix, const Action & r );
bool validate( const std::string & prefix, const ContactPhone & r );
bool validate( const std::string & prefix, const ContactPhoneWithId & r );
bool validate( const std::string & prefix, const Contact & r );
bool validate( const std::string & prefix, const ExtendedContactInfo & r );
bool validate( const std::string & prefix, const ReminderAction & r );
bool validate( const std::string & prefix, const ReminderOptions & r );
bool validate( const std::string & prefix, const Reminder & r );

// base messages
bool validate( const Request & r );
bool validate( const BackwardMessage & r );

// messages
bool validate( const GetJobInfoRequest & r );
bool validate( const GetJobInfoResponse & r );
bool validate( const GetJobStatRequest & r );
bool validate( const GetJobStatResponse & r );
bool validate( const FindJobRequest & r );
bool validate( const FindJobResponse & r );
bool validate( const FindTemplatesRequest & r );
bool validate( const FindTemplatesResponse & r );
bool validate( const CancelJobRequest & r );
bool validate( const CancelJobResponse & r );
bool validate( const CancelJobsRequest & r );
bool validate( const CancelJobsResponse & r );
bool validate( const SayRequest & r );
bool validate( const SayResponse & r );
bool validate( const SayFeedbackRequest & r );
bool validate( const SayFeedbackResponse & r );
bool validate( const AddContactPhoneRequest & r );
bool validate( const AddContactPhoneResponse & r );
bool validate( const ModifyContactPhoneRequest & r );
bool validate( const ModifyContactPhoneResponse & r );
bool validate( const DeleteContactPhoneRequest & r );
bool validate( const DeleteContactPhoneResponse & r );
bool validate( const GetContactPhoneRequest & r );
bool validate( const GetContactPhoneResponse & r );
bool validate( const AddContactRequest & r );
bool validate( const AddContactResponse & r );
bool validate( const ModifyContactRequest & r );
bool validate( const ModifyContactResponse & r );
bool validate( const DeleteContactRequest & r );
bool validate( const DeleteContactResponse & r );
bool validate( const GetContactRequest & r );
bool validate( const GetContactResponse & r );
bool validate( const GetContactWithPhonesRequest & r );
bool validate( const GetContactWithPhonesResponse & r );
bool validate( const GetContactExtRequest & r );
bool validate( const GetContactExtResponse & r );
bool validate( const GetExtendedContactInfoRequest & r );
bool validate( const GetExtendedContactInfoResponse & r );
bool validate( const SetExtendedContactInfoRequest & r );
bool validate( const SetExtendedContactInfoResponse & r );
bool validate( const AddReminderRequest & r );
bool validate( const AddReminderResponse & r );
bool validate( const ModifyReminderRequest & r );
bool validate( const ModifyReminderResponse & r );
bool validate( const GetReminderRequest & r );
bool validate( const GetReminderResponse & r );
bool validate( const GetReminderStatusRequest & r );

} // namespace validator

} // namespace persek_protocol

#endif // APG_PERSEK__VALIDATOR_H
