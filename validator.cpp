// includes
#include "validator.h"
#include "generic_protocol/validator.h"
#include "basic_objects/validator.h"
#include "dtmf_tools_protocol/validator.h"
#include "lang_tools_protocol/validator.h"
#include "basic_parser/validator.h"

namespace persek_protocol
{

namespace validator
{

using ::basic_parser::validator::validate;
using ::basic_parser::validator::validate_t;

// enums

bool validate( const std::string & prefix, const voice_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( voice_e::UNDEF ), true, true, static_cast<unsigned>( voice_e::FEMALE_A ) );

    return true;
}

bool validate( const std::string & prefix, const urgency_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( urgency_e::UNDEF ), true, true, static_cast<unsigned>( urgency_e::TIMED ) );

    return true;
}

bool validate( const std::string & prefix, const JobInfo_type_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( JobInfo_type_e::UNDEF ), true, true, static_cast<unsigned>( JobInfo_type_e::REMINDER ) );

    return true;
}

bool validate( const std::string & prefix, const exit_status_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( exit_status_e::DONE ), true, true, static_cast<unsigned>( exit_status_e::ABORTED_BY_RECIPIENT ) );

    return true;
}

bool validate( const std::string & prefix, const OpenJobStatus_state_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( OpenJobStatus_state_e::IDLE ), true, true, static_cast<unsigned>( OpenJobStatus_state_e::WAITING_REDIAL_TIMER ) );

    return true;
}

bool validate( const std::string & prefix, const FindJobRequest_status_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( FindJobRequest_status_e::ANY ), true, true, static_cast<unsigned>( FindJobRequest_status_e::CLOSED ) );

    return true;
}

bool validate( const std::string & prefix, const action_type_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( action_type_e::NONE ), true, true, static_cast<unsigned>( action_type_e::DROP ) );

    return true;
}

bool validate( const std::string & prefix, const ContactPhone_type_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( ContactPhone_type_e::DFLT ), true, true, static_cast<unsigned>( ContactPhone_type_e::MOBILE ) );

    return true;
}

bool validate( const std::string & prefix, const gender_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( gender_e::UNDEF ), true, true, static_cast<unsigned>( gender_e::FEMALE ) );

    return true;
}

bool validate( const std::string & prefix, const ReminderAction_type_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( ReminderAction_type_e::NONE ), true, true, static_cast<unsigned>( ReminderAction_type_e::DROP_SNOOZE ) );

    return true;
}

// objects

bool validate( const std::string & prefix, const JobOptions & r )
{
    validate( prefix + ".VOICE", r.voice );
    validate( prefix + ".URGENCY", r.urgency );
    ::lang_tools::validator::validate( prefix + ".LANG", r.lang );
    validate( prefix + ".EXEC_TIME", r.exec_time );
    validate( prefix + ".MAX_TRIES", r.max_tries );
    validate( prefix + ".REDIAL_IF_NO_FEEDBACK", r.redial_if_no_feedback );
    ::basic_objects::validator::validate( prefix + ".TIME_WINDOW", r.time_window );
    ::basic_objects::validator::validate( prefix + ".WEEKDAYS_MASK", r.weekdays_mask );

    return true;
}

bool validate( const std::string & prefix, const JobInfo & r )
{
    validate( prefix + ".JOB_ID", r.job_id );
    validate( prefix + ".USER_ID", r.user_id );
    validate( prefix + ".TYPE", r.type );
    validate( prefix + ".CONTACT", r.contact ); // String
    validate( prefix + ".CREATION_TIME", r.creation_time );
    validate( prefix + ".OPTIONS", r.options );

    return true;
}

bool validate( const std::string & prefix, const ClosedJobStatus & r )
{
    validate( prefix + ".JOB_ID", r.job_id );
    validate( prefix + ".EXIT_CODE", r.exit_code );
    validate_t( prefix + ".FEEDBACK", r.feedback, static_cast<bool (*)( const std::string &, uint32_t )>( &validate ) ); // Array
    validate( prefix + ".NUM_TRIES", r.num_tries );
    validate( prefix + ".TIMESTAMP", r.timestamp );
    validate( prefix + ".COMMENT", r.comment ); // String

    return true;
}

bool validate( const std::string & prefix, const OpenJobStatus & r )
{
    validate( prefix + ".JOB_ID", r.job_id );
    validate( prefix + ".STATE", r.state );
    validate( prefix + ".CURRENT_TRY", r.current_try );
    validate( prefix + ".TIMESTAMP", r.timestamp );
    validate( prefix + ".NEXT_EXEC_TIME", r.next_exec_time );

    return true;
}

bool validate( const std::string & prefix, const TemplateInfo & r )
{
    validate( prefix + ".ID", r.id );
    validate( prefix + ".CATEGORY_ID", r.category_id );
    validate( prefix + ".NAME", r.name ); // String
    ::lang_tools::validator::validate( prefix + ".LANG", r.lang );
    validate( prefix + ".LOCALIZED_NAME", r.localized_name ); // String
    validate_t( prefix + ".PLACEHOLDERS", r.placeholders, static_cast<bool (*)( const std::string &, const std::string &  )>( &validate ) ); // Array

    return true;
}

bool validate( const std::string & prefix, const CancellationFailureReason & r )
{
    validate( prefix + ".JOB_ID", r.job_id );
    ::generic_protocol::validator::validate( prefix + ".TYPE", r.type );
    validate( prefix + ".DESCR", r.descr ); // String

    return true;
}

bool validate( const std::string & prefix, const Action & r )
{
    validate( prefix + ".TYPE", r.type );
    validate( prefix + ".MSG_TEMPL_ID", r.msg_templ_id );

    return true;
}

bool validate( const std::string & prefix, const ContactPhone & r )
{
    validate( prefix + ".TYPE", r.type );
    validate( prefix + ".PHONE_NUMBER", r.phone_number ); // String

    return true;
}

bool validate( const std::string & prefix, const ContactPhoneWithId & r )
{
    validate( prefix + ".CONTACT_PHONE_ID", r.contact_phone_id );
    validate( prefix + ".CONTACT_PHONE", r.contact_phone );

    return true;
}

bool validate( const std::string & prefix, const Contact & r )
{
    validate( prefix + ".GENDER", r.gender );
    validate( prefix + ".NAME", r.name ); // String
    validate( prefix + ".FIRST_NAME", r.first_name ); // String
    ::basic_objects::validator::validate( prefix + ".BIRTHDAY", r.birthday );
    validate( prefix + ".NOTICE", r.notice ); // String

    return true;
}

bool validate( const std::string & prefix, const ExtendedContactInfo & r )
{
    validate( prefix + ".VOICE", r.voice );
    ::lang_tools::validator::validate( prefix + ".LANG", r.lang );
    validate( prefix + ".MAX_TRIES", r.max_tries );
    validate( prefix + ".REDIAL_IF_NO_FEEDBACK", r.redial_if_no_feedback );
    ::basic_objects::validator::validate( prefix + ".TIME_WINDOW", r.time_window );
    ::basic_objects::validator::validate( prefix + ".WEEKDAYS", r.weekdays );

    return true;
}

bool validate( const std::string & prefix, const ReminderAction & r )
{
    validate( prefix + ".TYPE", r.type );
    validate( prefix + ".MSG_TEMPL_ID", r.msg_templ_id );

    return true;
}

bool validate( const std::string & prefix, const ReminderOptions & r )
{
    validate( prefix + ".VOICE", r.voice );
    ::lang_tools::validator::validate( prefix + ".LANG", r.lang );
    validate( prefix + ".MAX_TRIES", r.max_tries );
    validate( prefix + ".REDIAL_IF_NO_FEEDBACK", r.redial_if_no_feedback );
    ::basic_objects::validator::validate( prefix + ".TIME_WINDOW", r.time_window );
    ::basic_objects::validator::validate( prefix + ".WEEKDAYS", r.weekdays );

    return true;
}

bool validate( const std::string & prefix, const Reminder & r )
{
    validate( prefix + ".MSG_TEMPL_ID", r.msg_templ_id );
    validate( prefix + ".FEEDBACK_TEMPL_ID", r.feedback_templ_id );
    validate( prefix + ".EFFECTIVE_TIME", r.effective_time );
    validate( prefix + ".REMIND_PERIOD", r.remind_period );
    validate_t( prefix + ".PARAMS", r.params, static_cast<bool (*)( const std::string &, const std::string &  )>( &validate ), static_cast<bool (*)( const std::string &, const std::string &  )>( &validate ) ); // Map
    validate_t( prefix + ".ACTIONS", r.actions, static_cast<bool (*)( const std::string &, dtmf_tools::tone_e )>( &::dtmf_tools::validator::validate ), static_cast<bool (*)( const std::string &, const ReminderAction &  )>( &validate ) ); // Map
    validate( prefix + ".OPTIONS", r.options );

    return true;
}

// base messages

bool validate( const Request & r )
{

    return true;
}

bool validate( const BackwardMessage & r )
{

    return true;
}

// messages

bool validate( const GetJobInfoRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "USER_ID", r.user_id );
    validate_t( "JOB_IDS", r.job_ids, static_cast<bool (*)( const std::string &, uint32_t )>( &validate ) ); // Array

    return true;
}

bool validate( const GetJobInfoResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate_t( "JOBS", r.jobs, static_cast<bool (*)( const std::string &, const JobInfo &  )>( &validate ) ); // Array

    return true;
}

bool validate( const GetJobStatRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "USER_ID", r.user_id );
    validate_t( "JOB_IDS", r.job_ids, static_cast<bool (*)( const std::string &, uint32_t )>( &validate ) ); // Array

    return true;
}

bool validate( const GetJobStatResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate_t( "OPEN_JOBS", r.open_jobs, static_cast<bool (*)( const std::string &, const OpenJobStatus &  )>( &validate ) ); // Array
    validate_t( "CLOSED_JOBS", r.closed_jobs, static_cast<bool (*)( const std::string &, const ClosedJobStatus &  )>( &validate ) ); // Array

    return true;
}

bool validate( const FindJobRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "USER_ID", r.user_id );
    validate( "STATUS", r.status );
    validate( "CONTACT_REGEX", r.contact_regex ); // String
    ::basic_objects::validator::validate( "CREATION_TIME_RANGE", r.creation_time_range );
    ::basic_objects::validator::validate( "EXEC_TIME_RANGE", r.exec_time_range );
    ::basic_objects::validator::validate( "UPDATE_TIME_RANGE", r.update_time_range );
    validate( "MAX_RESULTS", r.max_results );
    validate( "OFFSET", r.offset );

    return true;
}

bool validate( const FindJobResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "TOTAL_SIZE", r.total_size );
    validate_t( "JOB_IDS", r.job_ids, static_cast<bool (*)( const std::string &, uint32_t )>( &validate ) ); // Array

    return true;
}

bool validate( const FindTemplatesRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "USER_ID", r.user_id );
    validate( "CATEGORY_ID", r.category_id );
    validate( "NAME_REGEX", r.name_regex ); // String
    ::lang_tools::validator::validate( "LANG", r.lang );

    return true;
}

bool validate( const FindTemplatesResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate_t( "TEMPLATES", r.templates, static_cast<bool (*)( const std::string &, const TemplateInfo &  )>( &validate ) ); // Array

    return true;
}

bool validate( const CancelJobRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "JOB_ID", r.job_id );

    return true;
}

bool validate( const CancelJobResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );


    return true;
}

bool validate( const CancelJobsRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate_t( "JOB_IDS", r.job_ids, static_cast<bool (*)( const std::string &, uint32_t )>( &validate ) ); // Array

    return true;
}

bool validate( const CancelJobsResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate_t( "CANCELLED_JOB_IDS", r.cancelled_job_ids, static_cast<bool (*)( const std::string &, uint32_t )>( &validate ) ); // Array
    validate_t( "FAILED_JOBS", r.failed_jobs, static_cast<bool (*)( const std::string &, const CancellationFailureReason &  )>( &validate ) ); // Array

    return true;
}

bool validate( const SayRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "USER_ID", r.user_id );
    validate( "CONTACT_ID", r.contact_id ); // String
    validate( "MSG_TEMPL_ID", r.msg_templ_id );
    validate_t( "PARAMS", r.params, static_cast<bool (*)( const std::string &, const std::string &  )>( &validate ), static_cast<bool (*)( const std::string &, const std::string &  )>( &validate ) ); // Map
    validate( "OPTIONS", r.options );

    return true;
}

bool validate( const SayResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "JOB_ID", r.job_id );

    return true;
}

bool validate( const SayFeedbackRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "USER_ID", r.user_id );
    validate( "CONTACT_ID", r.contact_id ); // String
    validate( "MSG_TEMPL_ID", r.msg_templ_id );
    validate( "FEEDBACK_TEMPL_ID", r.feedback_templ_id );
    validate_t( "PARAMS", r.params, static_cast<bool (*)( const std::string &, const std::string &  )>( &validate ), static_cast<bool (*)( const std::string &, const std::string &  )>( &validate ) ); // Map
    validate_t( "ACTIONS", r.actions, static_cast<bool (*)( const std::string &, dtmf_tools::tone_e )>( &::dtmf_tools::validator::validate ), static_cast<bool (*)( const std::string &, const Action &  )>( &validate ) ); // Map
    validate( "OPTIONS", r.options );

    return true;
}

bool validate( const SayFeedbackResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "JOB_ID", r.job_id );

    return true;
}

bool validate( const AddContactPhoneRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "CONTACT_ID", r.contact_id );
    validate( "CONTACT_PHONE", r.contact_phone );

    return true;
}

bool validate( const AddContactPhoneResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "CONTACT_PHONE_ID", r.contact_phone_id );

    return true;
}

bool validate( const ModifyContactPhoneRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "CONTACT_PHONE_ID", r.contact_phone_id );
    validate( "CONTACT_PHONE", r.contact_phone );

    return true;
}

bool validate( const ModifyContactPhoneResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );


    return true;
}

bool validate( const DeleteContactPhoneRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "CONTACT_PHONE_ID", r.contact_phone_id );

    return true;
}

bool validate( const DeleteContactPhoneResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );


    return true;
}

bool validate( const GetContactPhoneRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "CONTACT_PHONE_ID", r.contact_phone_id );

    return true;
}

bool validate( const GetContactPhoneResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "CONTACT_ID", r.contact_id );
    validate( "CONTACT_PHONE", r.contact_phone );

    return true;
}

bool validate( const AddContactRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "USER_ID", r.user_id );
    validate( "CONTACT", r.contact );

    return true;
}

bool validate( const AddContactResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "CONTACT_ID", r.contact_id );

    return true;
}

bool validate( const ModifyContactRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "CONTACT_ID", r.contact_id );
    validate( "CONTACT", r.contact );

    return true;
}

bool validate( const ModifyContactResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );


    return true;
}

bool validate( const DeleteContactRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "CONTACT_ID", r.contact_id );

    return true;
}

bool validate( const DeleteContactResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );


    return true;
}

bool validate( const GetContactRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "CONTACT_ID", r.contact_id );

    return true;
}

bool validate( const GetContactResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "CONTACT", r.contact );
    validate_t( "CONTACT_PHONE_IDS", r.contact_phone_ids, static_cast<bool (*)( const std::string &, uint32_t )>( &validate ) ); // Array

    return true;
}

bool validate( const GetContactWithPhonesRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "CONTACT_ID", r.contact_id );

    return true;
}

bool validate( const GetContactWithPhonesResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "CONTACT", r.contact );
    validate_t( "CONTACT_PHONES", r.contact_phones, static_cast<bool (*)( const std::string &, const ContactPhoneWithId &  )>( &validate ) ); // Array

    return true;
}

bool validate( const GetContactExtRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "CONTACT_ID", r.contact_id );

    return true;
}

bool validate( const GetContactExtResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "CONTACT", r.contact );
    validate_t( "CONTACT_PHONES", r.contact_phones, static_cast<bool (*)( const std::string &, const ContactPhoneWithId &  )>( &validate ) ); // Array
    validate( "EXTENDED_INFO", r.extended_info );

    return true;
}

bool validate( const GetExtendedContactInfoRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "CONTACT_ID", r.contact_id );

    return true;
}

bool validate( const GetExtendedContactInfoResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "EXTENDED_INFO", r.extended_info );

    return true;
}

bool validate( const SetExtendedContactInfoRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "CONTACT_ID", r.contact_id );
    validate( "EXTENDED_INFO", r.extended_info );

    return true;
}

bool validate( const SetExtendedContactInfoResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );


    return true;
}

bool validate( const AddReminderRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "CONTACT_PHONE_ID", r.contact_phone_id );
    validate( "REMINDER", r.reminder );

    return true;
}

bool validate( const AddReminderResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "JOB_ID", r.job_id );

    return true;
}

bool validate( const ModifyReminderRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "JOB_ID", r.job_id );
    validate( "CONTACT_PHONE_ID", r.contact_phone_id );
    validate( "REMINDER", r.reminder );

    return true;
}

bool validate( const ModifyReminderResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );


    return true;
}

bool validate( const GetReminderRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "JOB_ID", r.job_id );

    return true;
}

bool validate( const GetReminderResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "CONTACT_ID", r.contact_id );
    validate( "CONTACT_PHONE_ID", r.contact_phone_id );
    validate( "CONTACT_PHONE", r.contact_phone ); // String
    validate( "REMINDER", r.reminder );

    return true;
}

bool validate( const GetReminderStatusRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "USER_ID", r.user_id );
    validate( "SEARCH_FILTER", r.search_filter ); // String
    ::basic_objects::validator::validate( "EFFECTIVE_DATE_TIME_RANGE", r.effective_date_time_range );
    validate( "PAGE_SIZE", r.page_size );
    validate( "PAGE_NUMBER", r.page_number );

    return true;
}

} // namespace validator

} // namespace persek_protocol

