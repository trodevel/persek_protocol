#ifndef APG_PERSEK__CSV_HELPER_H
#define APG_PERSEK__CSV_HELPER_H

// system includes
#include <sstream>

// includes
#include "protocol.h"

namespace persek_protocol
{

namespace csv_helper
{

// enums
std::ostream & write( std::ostream & os, const voice_e r );
std::ostream & write( std::ostream & os, const urgency_e r );
std::ostream & write( std::ostream & os, const JobInfo_type_e r );
std::ostream & write( std::ostream & os, const exit_status_e r );
std::ostream & write( std::ostream & os, const OpenJobStatus_state_e r );
std::ostream & write( std::ostream & os, const FindJobRequest_status_e r );
std::ostream & write( std::ostream & os, const action_type_e r );
std::ostream & write( std::ostream & os, const ContactPhone_type_e r );
std::ostream & write( std::ostream & os, const gender_e r );
std::ostream & write( std::ostream & os, const ReminderAction_type_e r );

// objects
std::ostream & write( std::ostream & os, const JobOptions & r );
std::ostream & write( std::ostream & os, const JobInfo & r );
std::ostream & write( std::ostream & os, const ClosedJobStatus & r );
std::ostream & write( std::ostream & os, const OpenJobStatus & r );
std::ostream & write( std::ostream & os, const TemplateInfo & r );
std::ostream & write( std::ostream & os, const CancellationFailureReason & r );
std::ostream & write( std::ostream & os, const Action & r );
std::ostream & write( std::ostream & os, const ContactPhone & r );
std::ostream & write( std::ostream & os, const ContactPhoneWithId & r );
std::ostream & write( std::ostream & os, const Contact & r );
std::ostream & write( std::ostream & os, const ExtendedContactInfo & r );
std::ostream & write( std::ostream & os, const ReminderAction & r );
std::ostream & write( std::ostream & os, const ReminderOptions & r );
std::ostream & write( std::ostream & os, const Reminder & r );

// base messages
std::ostream & write( std::ostream & os, const Request & r );
std::ostream & write( std::ostream & os, const BackwardMessage & r );

// messages
std::ostream & write( std::ostream & os, const GetJobInfoRequest & r );
std::ostream & write( std::ostream & os, const GetJobInfoResponse & r );
std::ostream & write( std::ostream & os, const GetJobStatRequest & r );
std::ostream & write( std::ostream & os, const GetJobStatResponse & r );
std::ostream & write( std::ostream & os, const FindJobRequest & r );
std::ostream & write( std::ostream & os, const FindJobResponse & r );
std::ostream & write( std::ostream & os, const FindTemplatesRequest & r );
std::ostream & write( std::ostream & os, const FindTemplatesResponse & r );
std::ostream & write( std::ostream & os, const CancelJobRequest & r );
std::ostream & write( std::ostream & os, const CancelJobResponse & r );
std::ostream & write( std::ostream & os, const CancelJobsRequest & r );
std::ostream & write( std::ostream & os, const CancelJobsResponse & r );
std::ostream & write( std::ostream & os, const SayRequest & r );
std::ostream & write( std::ostream & os, const SayResponse & r );
std::ostream & write( std::ostream & os, const SayFeedbackRequest & r );
std::ostream & write( std::ostream & os, const SayFeedbackResponse & r );
std::ostream & write( std::ostream & os, const AddContactPhoneRequest & r );
std::ostream & write( std::ostream & os, const AddContactPhoneResponse & r );
std::ostream & write( std::ostream & os, const ModifyContactPhoneRequest & r );
std::ostream & write( std::ostream & os, const ModifyContactPhoneResponse & r );
std::ostream & write( std::ostream & os, const DeleteContactPhoneRequest & r );
std::ostream & write( std::ostream & os, const DeleteContactPhoneResponse & r );
std::ostream & write( std::ostream & os, const GetContactPhoneRequest & r );
std::ostream & write( std::ostream & os, const GetContactPhoneResponse & r );
std::ostream & write( std::ostream & os, const AddContactRequest & r );
std::ostream & write( std::ostream & os, const AddContactResponse & r );
std::ostream & write( std::ostream & os, const ModifyContactRequest & r );
std::ostream & write( std::ostream & os, const ModifyContactResponse & r );
std::ostream & write( std::ostream & os, const DeleteContactRequest & r );
std::ostream & write( std::ostream & os, const DeleteContactResponse & r );
std::ostream & write( std::ostream & os, const GetContactRequest & r );
std::ostream & write( std::ostream & os, const GetContactResponse & r );
std::ostream & write( std::ostream & os, const GetContactWithPhonesRequest & r );
std::ostream & write( std::ostream & os, const GetContactWithPhonesResponse & r );
std::ostream & write( std::ostream & os, const GetContactExtRequest & r );
std::ostream & write( std::ostream & os, const GetContactExtResponse & r );
std::ostream & write( std::ostream & os, const GetExtendedContactInfoRequest & r );
std::ostream & write( std::ostream & os, const GetExtendedContactInfoResponse & r );
std::ostream & write( std::ostream & os, const SetExtendedContactInfoRequest & r );
std::ostream & write( std::ostream & os, const SetExtendedContactInfoResponse & r );
std::ostream & write( std::ostream & os, const AddReminderRequest & r );
std::ostream & write( std::ostream & os, const AddReminderResponse & r );
std::ostream & write( std::ostream & os, const ModifyReminderRequest & r );
std::ostream & write( std::ostream & os, const ModifyReminderResponse & r );
std::ostream & write( std::ostream & os, const GetReminderRequest & r );
std::ostream & write( std::ostream & os, const GetReminderResponse & r );
std::ostream & write( std::ostream & os, const GetReminderStatusRequest & r );

// generic
std::ostream & write( std::ostream & os, const basic_parser::Object & r );

template<class T>
std::string to_csv( const T & l )
{
    std::ostringstream os;

    write( os, l );

    return os.str();
}

} // namespace csv_helper

} // namespace persek_protocol

#endif // APG_PERSEK__CSV_HELPER_H
