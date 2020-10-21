// system includes
#include <map>
#include <typeindex>

// includes
#include "csv_helper.h"
#include "generic_protocol/csv_helper.h"
#include "basic_objects/csv_helper.h"
#include "dtmf_tools_protocol/csv_helper.h"
#include "lang_tools_protocol/csv_helper.h"
#include "basic_parser/csv_helper.h"

namespace persek_protocol
{

namespace csv_helper
{

using ::basic_parser::csv_helper::write;
using ::basic_parser::csv_helper::write_t;

// enums

std::ostream & write( std::ostream & os, const voice_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

std::ostream & write( std::ostream & os, const urgency_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

std::ostream & write( std::ostream & os, const JobInfo_type_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

std::ostream & write( std::ostream & os, const exit_status_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

std::ostream & write( std::ostream & os, const OpenJobStatus_state_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

std::ostream & write( std::ostream & os, const FindJobRequest_status_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

std::ostream & write( std::ostream & os, const action_type_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

std::ostream & write( std::ostream & os, const ContactPhone_type_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

std::ostream & write( std::ostream & os, const gender_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

std::ostream & write( std::ostream & os, const ReminderAction_type_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

// objects

std::ostream & write( std::ostream & os, const JobOptions & r )
{
    write( os, r.voice );
    write( os, r.urgency );
    ::lang_tools_protocol::csv_helper::write( os, r.lang );
    write( os, r.exec_time );
    write( os, r.max_tries );
    write( os, r.redial_if_no_feedback );
    ::basic_objects::csv_helper::write( os, r.time_window );
    ::basic_objects::csv_helper::write( os, r.weekdays_mask );

    return os;
}

std::ostream & write( std::ostream & os, const JobInfo & r )
{
    write( os, r.job_id );
    write( os, r.user_id );
    write( os, r.type );
    write( os, r.contact );
    write( os, r.creation_time );
    write( os, r.options );

    return os;
}

std::ostream & write( std::ostream & os, const ClosedJobStatus & r )
{
    write( os, r.job_id );
    write( os, r.exit_code );
    write_t( os, r.feedback, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array
    write( os, r.num_tries );
    write( os, r.timestamp );
    write( os, r.comment );

    return os;
}

std::ostream & write( std::ostream & os, const OpenJobStatus & r )
{
    write( os, r.job_id );
    write( os, r.state );
    write( os, r.current_try );
    write( os, r.timestamp );
    write( os, r.next_exec_time );

    return os;
}

std::ostream & write( std::ostream & os, const TemplateInfo & r )
{
    write( os, r.id );
    write( os, r.category_id );
    write( os, r.name );
    ::lang_tools_protocol::csv_helper::write( os, r.lang );
    write( os, r.localized_name );
    write_t( os, r.placeholders, static_cast<std::ostream & (*)( std::ostream &, const std::string &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const CancellationFailureReason & r )
{
    write( os, r.job_id );
    ::generic_protocol::csv_helper::write( os, r.type );
    write( os, r.descr );

    return os;
}

std::ostream & write( std::ostream & os, const Action & r )
{
    write( os, r.type );
    write( os, r.msg_templ_id );

    return os;
}

std::ostream & write( std::ostream & os, const ContactPhone & r )
{
    write( os, r.type );
    write( os, r.phone_number );

    return os;
}

std::ostream & write( std::ostream & os, const ContactPhoneWithId & r )
{
    write( os, r.contact_phone_id );
    write( os, r.contact_phone );

    return os;
}

std::ostream & write( std::ostream & os, const Contact & r )
{
    write( os, r.gender );
    write( os, r.name );
    write( os, r.first_name );
    ::basic_objects::csv_helper::write( os, r.birthday );
    write( os, r.notice );

    return os;
}

std::ostream & write( std::ostream & os, const ExtendedContactInfo & r )
{
    write( os, r.voice );
    ::lang_tools_protocol::csv_helper::write( os, r.lang );
    write( os, r.max_tries );
    write( os, r.redial_if_no_feedback );
    ::basic_objects::csv_helper::write( os, r.time_window );
    ::basic_objects::csv_helper::write( os, r.weekdays );

    return os;
}

std::ostream & write( std::ostream & os, const ReminderAction & r )
{
    write( os, r.type );
    write( os, r.msg_templ_id );

    return os;
}

std::ostream & write( std::ostream & os, const ReminderOptions & r )
{
    write( os, r.voice );
    ::lang_tools_protocol::csv_helper::write( os, r.lang );
    write( os, r.max_tries );
    write( os, r.redial_if_no_feedback );
    ::basic_objects::csv_helper::write( os, r.time_window );
    ::basic_objects::csv_helper::write( os, r.weekdays );

    return os;
}

std::ostream & write( std::ostream & os, const Reminder & r )
{
    write( os, r.msg_templ_id );
    write( os, r.feedback_templ_id );
    write( os, r.effective_time );
    write( os, r.remind_period );
    write_t( os, r.params, static_cast<std::ostream & (*)( std::ostream &, const std::string &  )>( &write ), static_cast<std::ostream & (*)( std::ostream &, const std::string &  )>( &write ) ); // Map
    write_t( os, r.actions, static_cast<std::ostream & (*)( std::ostream &, dtmf_tools_protocol::tone_e )>( &::dtmf_tools_protocol::csv_helper::write ), static_cast<std::ostream & (*)( std::ostream &, const ReminderAction &  )>( &write ) ); // Map
    write( os, r.options );

    return os;
}

// base messages

std::ostream & write( std::ostream & os, const Request & r )
{
    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::Request&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const BackwardMessage & r )
{
    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

// messages

std::ostream & write( std::ostream & os, const GetJobInfoRequest & r )
{
    write( os, std::string( "persek_protocol/GetJobInfoRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.user_id );
    write_t( os, r.job_ids, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GetJobInfoResponse & r )
{
    write( os, std::string( "persek_protocol/GetJobInfoResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write_t( os, r.jobs, static_cast<std::ostream & (*)( std::ostream &, const JobInfo &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GetJobStatRequest & r )
{
    write( os, std::string( "persek_protocol/GetJobStatRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.user_id );
    write_t( os, r.job_ids, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GetJobStatResponse & r )
{
    write( os, std::string( "persek_protocol/GetJobStatResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write_t( os, r.open_jobs, static_cast<std::ostream & (*)( std::ostream &, const OpenJobStatus &  )>( &write ) ); // Array
    write_t( os, r.closed_jobs, static_cast<std::ostream & (*)( std::ostream &, const ClosedJobStatus &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const FindJobRequest & r )
{
    write( os, std::string( "persek_protocol/FindJobRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.user_id );
    write( os, r.status );
    write( os, r.contact_regex );
    ::basic_objects::csv_helper::write( os, r.creation_time_range );
    ::basic_objects::csv_helper::write( os, r.exec_time_range );
    ::basic_objects::csv_helper::write( os, r.update_time_range );
    write( os, r.max_results );
    write( os, r.offset );

    return os;
}

std::ostream & write( std::ostream & os, const FindJobResponse & r )
{
    write( os, std::string( "persek_protocol/FindJobResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.total_size );
    write_t( os, r.job_ids, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const FindTemplatesRequest & r )
{
    write( os, std::string( "persek_protocol/FindTemplatesRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.user_id );
    write( os, r.category_id );
    write( os, r.name_regex );
    ::lang_tools_protocol::csv_helper::write( os, r.lang );

    return os;
}

std::ostream & write( std::ostream & os, const FindTemplatesResponse & r )
{
    write( os, std::string( "persek_protocol/FindTemplatesResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write_t( os, r.templates, static_cast<std::ostream & (*)( std::ostream &, const TemplateInfo &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const CancelJobRequest & r )
{
    write( os, std::string( "persek_protocol/CancelJobRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.job_id );

    return os;
}

std::ostream & write( std::ostream & os, const CancelJobResponse & r )
{
    write( os, std::string( "persek_protocol/CancelJobResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const CancelJobsRequest & r )
{
    write( os, std::string( "persek_protocol/CancelJobsRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write_t( os, r.job_ids, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const CancelJobsResponse & r )
{
    write( os, std::string( "persek_protocol/CancelJobsResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write_t( os, r.cancelled_job_ids, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array
    write_t( os, r.failed_jobs, static_cast<std::ostream & (*)( std::ostream &, const CancellationFailureReason &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const SayRequest & r )
{
    write( os, std::string( "persek_protocol/SayRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.user_id );
    write( os, r.contact_id );
    write( os, r.msg_templ_id );
    write_t( os, r.params, static_cast<std::ostream & (*)( std::ostream &, const std::string &  )>( &write ), static_cast<std::ostream & (*)( std::ostream &, const std::string &  )>( &write ) ); // Map
    write( os, r.options );

    return os;
}

std::ostream & write( std::ostream & os, const SayResponse & r )
{
    write( os, std::string( "persek_protocol/SayResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.job_id );

    return os;
}

std::ostream & write( std::ostream & os, const SayFeedbackRequest & r )
{
    write( os, std::string( "persek_protocol/SayFeedbackRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.user_id );
    write( os, r.contact_id );
    write( os, r.msg_templ_id );
    write( os, r.feedback_templ_id );
    write_t( os, r.params, static_cast<std::ostream & (*)( std::ostream &, const std::string &  )>( &write ), static_cast<std::ostream & (*)( std::ostream &, const std::string &  )>( &write ) ); // Map
    write_t( os, r.actions, static_cast<std::ostream & (*)( std::ostream &, dtmf_tools_protocol::tone_e )>( &::dtmf_tools_protocol::csv_helper::write ), static_cast<std::ostream & (*)( std::ostream &, const Action &  )>( &write ) ); // Map
    write( os, r.options );

    return os;
}

std::ostream & write( std::ostream & os, const SayFeedbackResponse & r )
{
    write( os, std::string( "persek_protocol/SayFeedbackResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.job_id );

    return os;
}

std::ostream & write( std::ostream & os, const AddContactPhoneRequest & r )
{
    write( os, std::string( "persek_protocol/AddContactPhoneRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.contact_id );
    write( os, r.contact_phone );

    return os;
}

std::ostream & write( std::ostream & os, const AddContactPhoneResponse & r )
{
    write( os, std::string( "persek_protocol/AddContactPhoneResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.contact_phone_id );

    return os;
}

std::ostream & write( std::ostream & os, const ModifyContactPhoneRequest & r )
{
    write( os, std::string( "persek_protocol/ModifyContactPhoneRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.contact_phone_id );
    write( os, r.contact_phone );

    return os;
}

std::ostream & write( std::ostream & os, const ModifyContactPhoneResponse & r )
{
    write( os, std::string( "persek_protocol/ModifyContactPhoneResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const DeleteContactPhoneRequest & r )
{
    write( os, std::string( "persek_protocol/DeleteContactPhoneRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.contact_phone_id );

    return os;
}

std::ostream & write( std::ostream & os, const DeleteContactPhoneResponse & r )
{
    write( os, std::string( "persek_protocol/DeleteContactPhoneResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const GetContactPhoneRequest & r )
{
    write( os, std::string( "persek_protocol/GetContactPhoneRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.contact_phone_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetContactPhoneResponse & r )
{
    write( os, std::string( "persek_protocol/GetContactPhoneResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.contact_id );
    write( os, r.contact_phone );

    return os;
}

std::ostream & write( std::ostream & os, const AddContactRequest & r )
{
    write( os, std::string( "persek_protocol/AddContactRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.user_id );
    write( os, r.contact );

    return os;
}

std::ostream & write( std::ostream & os, const AddContactResponse & r )
{
    write( os, std::string( "persek_protocol/AddContactResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.contact_id );

    return os;
}

std::ostream & write( std::ostream & os, const ModifyContactRequest & r )
{
    write( os, std::string( "persek_protocol/ModifyContactRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.contact_id );
    write( os, r.contact );

    return os;
}

std::ostream & write( std::ostream & os, const ModifyContactResponse & r )
{
    write( os, std::string( "persek_protocol/ModifyContactResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const DeleteContactRequest & r )
{
    write( os, std::string( "persek_protocol/DeleteContactRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.contact_id );

    return os;
}

std::ostream & write( std::ostream & os, const DeleteContactResponse & r )
{
    write( os, std::string( "persek_protocol/DeleteContactResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const GetContactRequest & r )
{
    write( os, std::string( "persek_protocol/GetContactRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.contact_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetContactResponse & r )
{
    write( os, std::string( "persek_protocol/GetContactResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.contact );
    write_t( os, r.contact_phone_ids, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GetContactWithPhonesRequest & r )
{
    write( os, std::string( "persek_protocol/GetContactWithPhonesRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.contact_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetContactWithPhonesResponse & r )
{
    write( os, std::string( "persek_protocol/GetContactWithPhonesResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.contact );
    write_t( os, r.contact_phones, static_cast<std::ostream & (*)( std::ostream &, const ContactPhoneWithId &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GetContactExtRequest & r )
{
    write( os, std::string( "persek_protocol/GetContactExtRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.contact_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetContactExtResponse & r )
{
    write( os, std::string( "persek_protocol/GetContactExtResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.contact );
    write_t( os, r.contact_phones, static_cast<std::ostream & (*)( std::ostream &, const ContactPhoneWithId &  )>( &write ) ); // Array
    write( os, r.extended_info );

    return os;
}

std::ostream & write( std::ostream & os, const GetExtendedContactInfoRequest & r )
{
    write( os, std::string( "persek_protocol/GetExtendedContactInfoRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.contact_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetExtendedContactInfoResponse & r )
{
    write( os, std::string( "persek_protocol/GetExtendedContactInfoResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.extended_info );

    return os;
}

std::ostream & write( std::ostream & os, const SetExtendedContactInfoRequest & r )
{
    write( os, std::string( "persek_protocol/SetExtendedContactInfoRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.contact_id );
    write( os, r.extended_info );

    return os;
}

std::ostream & write( std::ostream & os, const SetExtendedContactInfoResponse & r )
{
    write( os, std::string( "persek_protocol/SetExtendedContactInfoResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const AddReminderRequest & r )
{
    write( os, std::string( "persek_protocol/AddReminderRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.contact_phone_id );
    write( os, r.reminder );

    return os;
}

std::ostream & write( std::ostream & os, const AddReminderResponse & r )
{
    write( os, std::string( "persek_protocol/AddReminderResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.job_id );

    return os;
}

std::ostream & write( std::ostream & os, const ModifyReminderRequest & r )
{
    write( os, std::string( "persek_protocol/ModifyReminderRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.job_id );
    write( os, r.contact_phone_id );
    write( os, r.reminder );

    return os;
}

std::ostream & write( std::ostream & os, const ModifyReminderResponse & r )
{
    write( os, std::string( "persek_protocol/ModifyReminderResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const GetReminderRequest & r )
{
    write( os, std::string( "persek_protocol/GetReminderRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.job_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetReminderResponse & r )
{
    write( os, std::string( "persek_protocol/GetReminderResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.contact_id );
    write( os, r.contact_phone_id );
    write( os, r.contact_phone );
    write( os, r.reminder );

    return os;
}

std::ostream & write( std::ostream & os, const GetReminderStatusRequest & r )
{
    write( os, std::string( "persek_protocol/GetReminderStatusRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.user_id );
    write( os, r.search_filter );
    ::basic_objects::csv_helper::write( os, r.effective_date_time_range );
    write( os, r.page_size );
    write( os, r.page_number );

    return os;
}

std::ostream & write_GetJobInfoRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetJobInfoRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetJobInfoResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetJobInfoResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetJobStatRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetJobStatRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetJobStatResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetJobStatResponse &>( rr );

    return write( os, r );
}

std::ostream & write_FindJobRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const FindJobRequest &>( rr );

    return write( os, r );
}

std::ostream & write_FindJobResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const FindJobResponse &>( rr );

    return write( os, r );
}

std::ostream & write_FindTemplatesRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const FindTemplatesRequest &>( rr );

    return write( os, r );
}

std::ostream & write_FindTemplatesResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const FindTemplatesResponse &>( rr );

    return write( os, r );
}

std::ostream & write_CancelJobRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const CancelJobRequest &>( rr );

    return write( os, r );
}

std::ostream & write_CancelJobResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const CancelJobResponse &>( rr );

    return write( os, r );
}

std::ostream & write_CancelJobsRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const CancelJobsRequest &>( rr );

    return write( os, r );
}

std::ostream & write_CancelJobsResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const CancelJobsResponse &>( rr );

    return write( os, r );
}

std::ostream & write_SayRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const SayRequest &>( rr );

    return write( os, r );
}

std::ostream & write_SayResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const SayResponse &>( rr );

    return write( os, r );
}

std::ostream & write_SayFeedbackRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const SayFeedbackRequest &>( rr );

    return write( os, r );
}

std::ostream & write_SayFeedbackResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const SayFeedbackResponse &>( rr );

    return write( os, r );
}

std::ostream & write_AddContactPhoneRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AddContactPhoneRequest &>( rr );

    return write( os, r );
}

std::ostream & write_AddContactPhoneResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AddContactPhoneResponse &>( rr );

    return write( os, r );
}

std::ostream & write_ModifyContactPhoneRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const ModifyContactPhoneRequest &>( rr );

    return write( os, r );
}

std::ostream & write_ModifyContactPhoneResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const ModifyContactPhoneResponse &>( rr );

    return write( os, r );
}

std::ostream & write_DeleteContactPhoneRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const DeleteContactPhoneRequest &>( rr );

    return write( os, r );
}

std::ostream & write_DeleteContactPhoneResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const DeleteContactPhoneResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetContactPhoneRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetContactPhoneRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetContactPhoneResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetContactPhoneResponse &>( rr );

    return write( os, r );
}

std::ostream & write_AddContactRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AddContactRequest &>( rr );

    return write( os, r );
}

std::ostream & write_AddContactResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AddContactResponse &>( rr );

    return write( os, r );
}

std::ostream & write_ModifyContactRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const ModifyContactRequest &>( rr );

    return write( os, r );
}

std::ostream & write_ModifyContactResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const ModifyContactResponse &>( rr );

    return write( os, r );
}

std::ostream & write_DeleteContactRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const DeleteContactRequest &>( rr );

    return write( os, r );
}

std::ostream & write_DeleteContactResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const DeleteContactResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetContactRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetContactRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetContactResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetContactResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetContactWithPhonesRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetContactWithPhonesRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetContactWithPhonesResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetContactWithPhonesResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetContactExtRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetContactExtRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetContactExtResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetContactExtResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetExtendedContactInfoRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetExtendedContactInfoRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetExtendedContactInfoResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetExtendedContactInfoResponse &>( rr );

    return write( os, r );
}

std::ostream & write_SetExtendedContactInfoRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const SetExtendedContactInfoRequest &>( rr );

    return write( os, r );
}

std::ostream & write_SetExtendedContactInfoResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const SetExtendedContactInfoResponse &>( rr );

    return write( os, r );
}

std::ostream & write_AddReminderRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AddReminderRequest &>( rr );

    return write( os, r );
}

std::ostream & write_AddReminderResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AddReminderResponse &>( rr );

    return write( os, r );
}

std::ostream & write_ModifyReminderRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const ModifyReminderRequest &>( rr );

    return write( os, r );
}

std::ostream & write_ModifyReminderResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const ModifyReminderResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetReminderRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetReminderRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetReminderResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetReminderResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetReminderStatusRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetReminderStatusRequest &>( rr );

    return write( os, r );
}


std::ostream & write( std::ostream & os, const basic_parser::Object & r )
{
    typedef std::ostream & (*PPMF)( std::ostream & os, const basic_parser::Object & );

#define HANDLER_MAP_ENTRY(_v)       { typeid( _v ),        & write_##_v }

    static const std::map<std::type_index, PPMF> funcs =
    {
        HANDLER_MAP_ENTRY( GetJobInfoRequest ),
        HANDLER_MAP_ENTRY( GetJobInfoResponse ),
        HANDLER_MAP_ENTRY( GetJobStatRequest ),
        HANDLER_MAP_ENTRY( GetJobStatResponse ),
        HANDLER_MAP_ENTRY( FindJobRequest ),
        HANDLER_MAP_ENTRY( FindJobResponse ),
        HANDLER_MAP_ENTRY( FindTemplatesRequest ),
        HANDLER_MAP_ENTRY( FindTemplatesResponse ),
        HANDLER_MAP_ENTRY( CancelJobRequest ),
        HANDLER_MAP_ENTRY( CancelJobResponse ),
        HANDLER_MAP_ENTRY( CancelJobsRequest ),
        HANDLER_MAP_ENTRY( CancelJobsResponse ),
        HANDLER_MAP_ENTRY( SayRequest ),
        HANDLER_MAP_ENTRY( SayResponse ),
        HANDLER_MAP_ENTRY( SayFeedbackRequest ),
        HANDLER_MAP_ENTRY( SayFeedbackResponse ),
        HANDLER_MAP_ENTRY( AddContactPhoneRequest ),
        HANDLER_MAP_ENTRY( AddContactPhoneResponse ),
        HANDLER_MAP_ENTRY( ModifyContactPhoneRequest ),
        HANDLER_MAP_ENTRY( ModifyContactPhoneResponse ),
        HANDLER_MAP_ENTRY( DeleteContactPhoneRequest ),
        HANDLER_MAP_ENTRY( DeleteContactPhoneResponse ),
        HANDLER_MAP_ENTRY( GetContactPhoneRequest ),
        HANDLER_MAP_ENTRY( GetContactPhoneResponse ),
        HANDLER_MAP_ENTRY( AddContactRequest ),
        HANDLER_MAP_ENTRY( AddContactResponse ),
        HANDLER_MAP_ENTRY( ModifyContactRequest ),
        HANDLER_MAP_ENTRY( ModifyContactResponse ),
        HANDLER_MAP_ENTRY( DeleteContactRequest ),
        HANDLER_MAP_ENTRY( DeleteContactResponse ),
        HANDLER_MAP_ENTRY( GetContactRequest ),
        HANDLER_MAP_ENTRY( GetContactResponse ),
        HANDLER_MAP_ENTRY( GetContactWithPhonesRequest ),
        HANDLER_MAP_ENTRY( GetContactWithPhonesResponse ),
        HANDLER_MAP_ENTRY( GetContactExtRequest ),
        HANDLER_MAP_ENTRY( GetContactExtResponse ),
        HANDLER_MAP_ENTRY( GetExtendedContactInfoRequest ),
        HANDLER_MAP_ENTRY( GetExtendedContactInfoResponse ),
        HANDLER_MAP_ENTRY( SetExtendedContactInfoRequest ),
        HANDLER_MAP_ENTRY( SetExtendedContactInfoResponse ),
        HANDLER_MAP_ENTRY( AddReminderRequest ),
        HANDLER_MAP_ENTRY( AddReminderResponse ),
        HANDLER_MAP_ENTRY( ModifyReminderRequest ),
        HANDLER_MAP_ENTRY( ModifyReminderResponse ),
        HANDLER_MAP_ENTRY( GetReminderRequest ),
        HANDLER_MAP_ENTRY( GetReminderResponse ),
        HANDLER_MAP_ENTRY( GetReminderStatusRequest ),
    };

#undef HANDLER_MAP_ENTRY

    auto it = funcs.find( typeid( r ) );

    if( it != funcs.end() )
        return it->second( os, r );

    return ::generic_protocol::csv_helper::write( os, r );
}

} // namespace csv_helper

} // namespace persek_protocol

