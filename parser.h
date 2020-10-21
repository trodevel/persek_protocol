#ifndef APG_PERSEK_PROTOCOL__PARSER_H
#define APG_PERSEK_PROTOCOL__PARSER_H

// includes
#include "generic_request/request.h"
#include "enums.h"
#include "protocol.h"

namespace persek_protocol
{

namespace parser
{

typedef basic_parser::Object    Object;

basic_parser::Object * to_forward_message( const generic_request::Request & r );

request_type_e detect_request_type( const generic_request::Request & r );

// enums

void get_value_or_throw( voice_e * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( urgency_e * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( JobInfo_type_e * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( exit_status_e * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( OpenJobStatus_state_e * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( FindJobRequest_status_e * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( action_type_e * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( ContactPhone_type_e * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( gender_e * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( ReminderAction_type_e * res, const std::string & key, const generic_request::Request & r );

// objects

void get_value_or_throw( JobOptions * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( JobInfo * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( ClosedJobStatus * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( OpenJobStatus * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( TemplateInfo * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( CancellationFailureReason * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( Action * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( ContactPhone * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( ContactPhoneWithId * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( Contact * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( ExtendedContactInfo * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( ReminderAction * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( ReminderOptions * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( Reminder * res, const std::string & key, const generic_request::Request & r );

// base messages

void get_value_or_throw( Request * res, const generic_request::Request & r );
void get_value_or_throw( BackwardMessage * res, const generic_request::Request & r );

// messages

void get_value_or_throw( GetJobInfoRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetJobInfoResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetJobStatRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetJobStatResponse * res, const generic_request::Request & r );
void get_value_or_throw( FindJobRequest * res, const generic_request::Request & r );
void get_value_or_throw( FindJobResponse * res, const generic_request::Request & r );
void get_value_or_throw( FindTemplatesRequest * res, const generic_request::Request & r );
void get_value_or_throw( FindTemplatesResponse * res, const generic_request::Request & r );
void get_value_or_throw( CancelJobRequest * res, const generic_request::Request & r );
void get_value_or_throw( CancelJobResponse * res, const generic_request::Request & r );
void get_value_or_throw( CancelJobsRequest * res, const generic_request::Request & r );
void get_value_or_throw( CancelJobsResponse * res, const generic_request::Request & r );
void get_value_or_throw( SayRequest * res, const generic_request::Request & r );
void get_value_or_throw( SayResponse * res, const generic_request::Request & r );
void get_value_or_throw( SayFeedbackRequest * res, const generic_request::Request & r );
void get_value_or_throw( SayFeedbackResponse * res, const generic_request::Request & r );
void get_value_or_throw( AddContactPhoneRequest * res, const generic_request::Request & r );
void get_value_or_throw( AddContactPhoneResponse * res, const generic_request::Request & r );
void get_value_or_throw( ModifyContactPhoneRequest * res, const generic_request::Request & r );
void get_value_or_throw( ModifyContactPhoneResponse * res, const generic_request::Request & r );
void get_value_or_throw( DeleteContactPhoneRequest * res, const generic_request::Request & r );
void get_value_or_throw( DeleteContactPhoneResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetContactPhoneRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetContactPhoneResponse * res, const generic_request::Request & r );
void get_value_or_throw( AddContactRequest * res, const generic_request::Request & r );
void get_value_or_throw( AddContactResponse * res, const generic_request::Request & r );
void get_value_or_throw( ModifyContactRequest * res, const generic_request::Request & r );
void get_value_or_throw( ModifyContactResponse * res, const generic_request::Request & r );
void get_value_or_throw( DeleteContactRequest * res, const generic_request::Request & r );
void get_value_or_throw( DeleteContactResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetContactRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetContactResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetContactWithPhonesRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetContactWithPhonesResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetContactExtRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetContactExtResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetExtendedContactInfoRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetExtendedContactInfoResponse * res, const generic_request::Request & r );
void get_value_or_throw( SetExtendedContactInfoRequest * res, const generic_request::Request & r );
void get_value_or_throw( SetExtendedContactInfoResponse * res, const generic_request::Request & r );
void get_value_or_throw( AddReminderRequest * res, const generic_request::Request & r );
void get_value_or_throw( AddReminderResponse * res, const generic_request::Request & r );
void get_value_or_throw( ModifyReminderRequest * res, const generic_request::Request & r );
void get_value_or_throw( ModifyReminderResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetReminderRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetReminderResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetReminderStatusRequest * res, const generic_request::Request & r );

// to_... functions

Object * to_GetJobInfoRequest( const generic_request::Request & r );
Object * to_GetJobInfoResponse( const generic_request::Request & r );
Object * to_GetJobStatRequest( const generic_request::Request & r );
Object * to_GetJobStatResponse( const generic_request::Request & r );
Object * to_FindJobRequest( const generic_request::Request & r );
Object * to_FindJobResponse( const generic_request::Request & r );
Object * to_FindTemplatesRequest( const generic_request::Request & r );
Object * to_FindTemplatesResponse( const generic_request::Request & r );
Object * to_CancelJobRequest( const generic_request::Request & r );
Object * to_CancelJobResponse( const generic_request::Request & r );
Object * to_CancelJobsRequest( const generic_request::Request & r );
Object * to_CancelJobsResponse( const generic_request::Request & r );
Object * to_SayRequest( const generic_request::Request & r );
Object * to_SayResponse( const generic_request::Request & r );
Object * to_SayFeedbackRequest( const generic_request::Request & r );
Object * to_SayFeedbackResponse( const generic_request::Request & r );
Object * to_AddContactPhoneRequest( const generic_request::Request & r );
Object * to_AddContactPhoneResponse( const generic_request::Request & r );
Object * to_ModifyContactPhoneRequest( const generic_request::Request & r );
Object * to_ModifyContactPhoneResponse( const generic_request::Request & r );
Object * to_DeleteContactPhoneRequest( const generic_request::Request & r );
Object * to_DeleteContactPhoneResponse( const generic_request::Request & r );
Object * to_GetContactPhoneRequest( const generic_request::Request & r );
Object * to_GetContactPhoneResponse( const generic_request::Request & r );
Object * to_AddContactRequest( const generic_request::Request & r );
Object * to_AddContactResponse( const generic_request::Request & r );
Object * to_ModifyContactRequest( const generic_request::Request & r );
Object * to_ModifyContactResponse( const generic_request::Request & r );
Object * to_DeleteContactRequest( const generic_request::Request & r );
Object * to_DeleteContactResponse( const generic_request::Request & r );
Object * to_GetContactRequest( const generic_request::Request & r );
Object * to_GetContactResponse( const generic_request::Request & r );
Object * to_GetContactWithPhonesRequest( const generic_request::Request & r );
Object * to_GetContactWithPhonesResponse( const generic_request::Request & r );
Object * to_GetContactExtRequest( const generic_request::Request & r );
Object * to_GetContactExtResponse( const generic_request::Request & r );
Object * to_GetExtendedContactInfoRequest( const generic_request::Request & r );
Object * to_GetExtendedContactInfoResponse( const generic_request::Request & r );
Object * to_SetExtendedContactInfoRequest( const generic_request::Request & r );
Object * to_SetExtendedContactInfoResponse( const generic_request::Request & r );
Object * to_AddReminderRequest( const generic_request::Request & r );
Object * to_AddReminderResponse( const generic_request::Request & r );
Object * to_ModifyReminderRequest( const generic_request::Request & r );
Object * to_ModifyReminderResponse( const generic_request::Request & r );
Object * to_GetReminderRequest( const generic_request::Request & r );
Object * to_GetReminderResponse( const generic_request::Request & r );
Object * to_GetReminderStatusRequest( const generic_request::Request & r );

} // namespace parser

} // namespace persek_protocol

#endif // APG_PERSEK_PROTOCOL__PARSER_H
