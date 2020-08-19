// system includes
#include <map>

// includes
#include "str_helper.h"
#include "generic_protocol/str_helper.h"
#include "basic_objects/str_helper.h"
#include "dtmf_tools_protocol/str_helper.h"
#include "lang_tools_protocol/str_helper.h"
#include "basic_parser/str_helper.h"

namespace persek_protocol
{

namespace str_helper
{

using ::basic_parser::str_helper::write;
using ::basic_parser::str_helper::write_t;

// enums

#define TUPLE_VAL_STR(_x_)  _x_,#_x_

std::ostream & write( std::ostream & os, const voice_e r )
{
    typedef voice_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( MALE_A ) },
        { Type:: TUPLE_VAL_STR( FEMALE_A ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

std::ostream & write( std::ostream & os, const urgency_e r )
{
    typedef urgency_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( IMMEDIATE ) },
        { Type:: TUPLE_VAL_STR( TIMED ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

std::ostream & write( std::ostream & os, const JobInfo_type_e r )
{
    typedef JobInfo_type_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( SAY ) },
        { Type:: TUPLE_VAL_STR( SAY_FEEDBACK ) },
        { Type:: TUPLE_VAL_STR( FSM ) },
        { Type:: TUPLE_VAL_STR( REMINDER ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

std::ostream & write( std::ostream & os, const exit_status_e r )
{
    typedef exit_status_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( DONE ) },
        { Type:: TUPLE_VAL_STR( CANCELLED ) },
        { Type:: TUPLE_VAL_STR( FAILED ) },
        { Type:: TUPLE_VAL_STR( REFUSED_BY_RECIPIENT ) },
        { Type:: TUPLE_VAL_STR( ABORTED_BY_RECIPIENT ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

std::ostream & write( std::ostream & os, const OpenJobStatus_state_e r )
{
    typedef OpenJobStatus_state_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( IDLE ) },
        { Type:: TUPLE_VAL_STR( WAITING_PROC_STARTED ) },
        { Type:: TUPLE_VAL_STR( ACTIVE ) },
        { Type:: TUPLE_VAL_STR( WRONG_ACTIVE ) },
        { Type:: TUPLE_VAL_STR( CANCELLED_IN_A ) },
        { Type:: TUPLE_VAL_STR( CANCELLED_IN_WPS ) },
        { Type:: TUPLE_VAL_STR( COMPLETED ) },
        { Type:: TUPLE_VAL_STR( WAITING_REDIAL_TIMER ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

std::ostream & write( std::ostream & os, const FindJobRequest_status_e r )
{
    typedef FindJobRequest_status_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( ANY ) },
        { Type:: TUPLE_VAL_STR( OPEN ) },
        { Type:: TUPLE_VAL_STR( CLOSED ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

std::ostream & write( std::ostream & os, const action_type_e r )
{
    typedef action_type_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( NONE ) },
        { Type:: TUPLE_VAL_STR( REPEAT ) },
        { Type:: TUPLE_VAL_STR( DROP ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

std::ostream & write( std::ostream & os, const ContactPhone_type_e r )
{
    typedef ContactPhone_type_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( DFLT ) },
        { Type:: TUPLE_VAL_STR( LANDLINE ) },
        { Type:: TUPLE_VAL_STR( MOBILE ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

std::ostream & write( std::ostream & os, const gender_e r )
{
    typedef gender_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( MALE ) },
        { Type:: TUPLE_VAL_STR( FEMALE ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

std::ostream & write( std::ostream & os, const ReminderAction_type_e r )
{
    typedef ReminderAction_type_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( NONE ) },
        { Type:: TUPLE_VAL_STR( REPEAT ) },
        { Type:: TUPLE_VAL_STR( DROP_FEEDBACK ) },
        { Type:: TUPLE_VAL_STR( DROP_SNOOZE ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

// objects

std::ostream & write( std::ostream & os, const JobOptions & r )
{
    os << "(";

    os << " voice="; write( os, r.voice );
    os << " urgency="; write( os, r.urgency );
    os << " lang="; ::lang_tools::str_helper::write( os, r.lang );
    os << " exec_time="; write( os, r.exec_time );
    os << " max_tries="; write( os, r.max_tries );
    os << " redial_if_no_feedback="; write( os, r.redial_if_no_feedback );
    os << " time_window="; ::basic_objects::str_helper::write( os, r.time_window );
    os << " weekdays_mask="; ::basic_objects::str_helper::write( os, r.weekdays_mask );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const JobInfo & r )
{
    os << "(";

    os << " job_id="; write( os, r.job_id );
    os << " user_id="; write( os, r.user_id );
    os << " type="; write( os, r.type );
    os << " contact="; write( os, r.contact );
    os << " creation_time="; write( os, r.creation_time );
    os << " options="; write( os, r.options );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const ClosedJobStatus & r )
{
    os << "(";

    os << " job_id="; write( os, r.job_id );
    os << " exit_code="; write( os, r.exit_code );
    os << " feedback="; write_t( os, r.feedback, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array
    os << " num_tries="; write( os, r.num_tries );
    os << " timestamp="; write( os, r.timestamp );
    os << " comment="; write( os, r.comment );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const OpenJobStatus & r )
{
    os << "(";

    os << " job_id="; write( os, r.job_id );
    os << " state="; write( os, r.state );
    os << " current_try="; write( os, r.current_try );
    os << " timestamp="; write( os, r.timestamp );
    os << " next_exec_time="; write( os, r.next_exec_time );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const TemplateInfo & r )
{
    os << "(";

    os << " id="; write( os, r.id );
    os << " category_id="; write( os, r.category_id );
    os << " name="; write( os, r.name );
    os << " lang="; ::lang_tools::str_helper::write( os, r.lang );
    os << " localized_name="; write( os, r.localized_name );
    os << " placeholders="; write_t( os, r.placeholders, static_cast<std::ostream & (*)( std::ostream &, const std::string &  )>( &write ) ); // Array

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const CancellationFailureReason & r )
{
    os << "(";

    os << " job_id="; write( os, r.job_id );
    os << " type="; ::generic_protocol::str_helper::write( os, r.type );
    os << " descr="; write( os, r.descr );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const Action & r )
{
    os << "(";

    os << " type="; write( os, r.type );
    os << " msg_templ_id="; write( os, r.msg_templ_id );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const ContactPhone & r )
{
    os << "(";

    os << " type="; write( os, r.type );
    os << " phone_number="; write( os, r.phone_number );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const ContactPhoneWithId & r )
{
    os << "(";

    os << " contact_phone_id="; write( os, r.contact_phone_id );
    os << " contact_phone="; write( os, r.contact_phone );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const Contact & r )
{
    os << "(";

    os << " gender="; write( os, r.gender );
    os << " name="; write( os, r.name );
    os << " first_name="; write( os, r.first_name );
    os << " birthday="; ::basic_objects::str_helper::write( os, r.birthday );
    os << " notice="; write( os, r.notice );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const ExtendedContactInfo & r )
{
    os << "(";

    os << " voice="; write( os, r.voice );
    os << " lang="; ::lang_tools::str_helper::write( os, r.lang );
    os << " max_tries="; write( os, r.max_tries );
    os << " redial_if_no_feedback="; write( os, r.redial_if_no_feedback );
    os << " time_window="; ::basic_objects::str_helper::write( os, r.time_window );
    os << " weekdays="; ::basic_objects::str_helper::write( os, r.weekdays );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const ReminderAction & r )
{
    os << "(";

    os << " type="; write( os, r.type );
    os << " msg_templ_id="; write( os, r.msg_templ_id );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const ReminderOptions & r )
{
    os << "(";

    os << " voice="; write( os, r.voice );
    os << " lang="; ::lang_tools::str_helper::write( os, r.lang );
    os << " max_tries="; write( os, r.max_tries );
    os << " redial_if_no_feedback="; write( os, r.redial_if_no_feedback );
    os << " time_window="; ::basic_objects::str_helper::write( os, r.time_window );
    os << " weekdays="; ::basic_objects::str_helper::write( os, r.weekdays );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const Reminder & r )
{
    os << "(";

    os << " msg_templ_id="; write( os, r.msg_templ_id );
    os << " feedback_templ_id="; write( os, r.feedback_templ_id );
    os << " effective_time="; write( os, r.effective_time );
    os << " remind_period="; write( os, r.remind_period );
    os << " params="; write_t( os, r.params, static_cast<std::ostream & (*)( std::ostream &, const std::string &  )>( &write ), static_cast<std::ostream & (*)( std::ostream &, const std::string &  )>( &write ) ); // Map
    os << " actions="; write_t( os, r.actions, static_cast<std::ostream & (*)( std::ostream &, dtmf_tools::tone_e )>( &::dtmf_tools::str_helper::write ), static_cast<std::ostream & (*)( std::ostream &, const ReminderAction &  )>( &write ) ); // Map
    os << " options="; write( os, r.options );

    os << ")";

    return os;
}

// base messages

std::ostream & write( std::ostream & os, const Request & r )
{
    os << "(";


    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const BackwardMessage & r )
{
    os << "(";


    os << ")";

    return os;
}

// messages

std::ostream & write( std::ostream & os, const GetJobInfoRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " user_id="; write( os, r.user_id );
    os << " job_ids="; write_t( os, r.job_ids, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GetJobInfoResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " jobs="; write_t( os, r.jobs, static_cast<std::ostream & (*)( std::ostream &, const JobInfo &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GetJobStatRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " user_id="; write( os, r.user_id );
    os << " job_ids="; write_t( os, r.job_ids, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GetJobStatResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " open_jobs="; write_t( os, r.open_jobs, static_cast<std::ostream & (*)( std::ostream &, const OpenJobStatus &  )>( &write ) ); // Array
    os << " closed_jobs="; write_t( os, r.closed_jobs, static_cast<std::ostream & (*)( std::ostream &, const ClosedJobStatus &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const FindJobRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " user_id="; write( os, r.user_id );
    os << " status="; write( os, r.status );
    os << " contact_regex="; write( os, r.contact_regex );
    os << " creation_time_range="; ::basic_objects::str_helper::write( os, r.creation_time_range );
    os << " exec_time_range="; ::basic_objects::str_helper::write( os, r.exec_time_range );
    os << " update_time_range="; ::basic_objects::str_helper::write( os, r.update_time_range );
    os << " max_results="; write( os, r.max_results );
    os << " offset="; write( os, r.offset );

    return os;
}

std::ostream & write( std::ostream & os, const FindJobResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " total_size="; write( os, r.total_size );
    os << " job_ids="; write_t( os, r.job_ids, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const FindTemplatesRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " user_id="; write( os, r.user_id );
    os << " category_id="; write( os, r.category_id );
    os << " name_regex="; write( os, r.name_regex );
    os << " lang="; ::lang_tools::str_helper::write( os, r.lang );

    return os;
}

std::ostream & write( std::ostream & os, const FindTemplatesResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " templates="; write_t( os, r.templates, static_cast<std::ostream & (*)( std::ostream &, const TemplateInfo &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const CancelJobRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " job_id="; write( os, r.job_id );

    return os;
}

std::ostream & write( std::ostream & os, const CancelJobResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const CancelJobsRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " job_ids="; write_t( os, r.job_ids, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const CancelJobsResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " cancelled_job_ids="; write_t( os, r.cancelled_job_ids, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array
    os << " failed_jobs="; write_t( os, r.failed_jobs, static_cast<std::ostream & (*)( std::ostream &, const CancellationFailureReason &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const SayRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " user_id="; write( os, r.user_id );
    os << " contact_id="; write( os, r.contact_id );
    os << " msg_templ_id="; write( os, r.msg_templ_id );
    os << " params="; write_t( os, r.params, static_cast<std::ostream & (*)( std::ostream &, const std::string &  )>( &write ), static_cast<std::ostream & (*)( std::ostream &, const std::string &  )>( &write ) ); // Map
    os << " options="; write( os, r.options );

    return os;
}

std::ostream & write( std::ostream & os, const SayResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " job_id="; write( os, r.job_id );

    return os;
}

std::ostream & write( std::ostream & os, const SayFeedbackRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " user_id="; write( os, r.user_id );
    os << " contact_id="; write( os, r.contact_id );
    os << " msg_templ_id="; write( os, r.msg_templ_id );
    os << " feedback_templ_id="; write( os, r.feedback_templ_id );
    os << " params="; write_t( os, r.params, static_cast<std::ostream & (*)( std::ostream &, const std::string &  )>( &write ), static_cast<std::ostream & (*)( std::ostream &, const std::string &  )>( &write ) ); // Map
    os << " actions="; write_t( os, r.actions, static_cast<std::ostream & (*)( std::ostream &, dtmf_tools::tone_e )>( &::dtmf_tools::str_helper::write ), static_cast<std::ostream & (*)( std::ostream &, const Action &  )>( &write ) ); // Map
    os << " options="; write( os, r.options );

    return os;
}

std::ostream & write( std::ostream & os, const SayFeedbackResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " job_id="; write( os, r.job_id );

    return os;
}

std::ostream & write( std::ostream & os, const AddContactPhoneRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " contact_id="; write( os, r.contact_id );
    os << " contact_phone="; write( os, r.contact_phone );

    return os;
}

std::ostream & write( std::ostream & os, const AddContactPhoneResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " contact_phone_id="; write( os, r.contact_phone_id );

    return os;
}

std::ostream & write( std::ostream & os, const ModifyContactPhoneRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " contact_phone_id="; write( os, r.contact_phone_id );
    os << " contact_phone="; write( os, r.contact_phone );

    return os;
}

std::ostream & write( std::ostream & os, const ModifyContactPhoneResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const DeleteContactPhoneRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " contact_phone_id="; write( os, r.contact_phone_id );

    return os;
}

std::ostream & write( std::ostream & os, const DeleteContactPhoneResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const GetContactPhoneRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " contact_phone_id="; write( os, r.contact_phone_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetContactPhoneResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " contact_id="; write( os, r.contact_id );
    os << " contact_phone="; write( os, r.contact_phone );

    return os;
}

std::ostream & write( std::ostream & os, const AddContactRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " user_id="; write( os, r.user_id );
    os << " contact="; write( os, r.contact );

    return os;
}

std::ostream & write( std::ostream & os, const AddContactResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " contact_id="; write( os, r.contact_id );

    return os;
}

std::ostream & write( std::ostream & os, const ModifyContactRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " contact_id="; write( os, r.contact_id );
    os << " contact="; write( os, r.contact );

    return os;
}

std::ostream & write( std::ostream & os, const ModifyContactResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const DeleteContactRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " contact_id="; write( os, r.contact_id );

    return os;
}

std::ostream & write( std::ostream & os, const DeleteContactResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const GetContactRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " contact_id="; write( os, r.contact_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetContactResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " contact="; write( os, r.contact );
    os << " contact_phone_ids="; write_t( os, r.contact_phone_ids, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GetContactWithPhonesRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " contact_id="; write( os, r.contact_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetContactWithPhonesResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " contact="; write( os, r.contact );
    os << " contact_phones="; write_t( os, r.contact_phones, static_cast<std::ostream & (*)( std::ostream &, const ContactPhoneWithId &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GetContactExtRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " contact_id="; write( os, r.contact_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetContactExtResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " contact="; write( os, r.contact );
    os << " contact_phones="; write_t( os, r.contact_phones, static_cast<std::ostream & (*)( std::ostream &, const ContactPhoneWithId &  )>( &write ) ); // Array
    os << " extended_info="; write( os, r.extended_info );

    return os;
}

std::ostream & write( std::ostream & os, const GetExtendedContactInfoRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " contact_id="; write( os, r.contact_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetExtendedContactInfoResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " extended_info="; write( os, r.extended_info );

    return os;
}

std::ostream & write( std::ostream & os, const SetExtendedContactInfoRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " contact_id="; write( os, r.contact_id );
    os << " extended_info="; write( os, r.extended_info );

    return os;
}

std::ostream & write( std::ostream & os, const SetExtendedContactInfoResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const AddReminderRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " contact_phone_id="; write( os, r.contact_phone_id );
    os << " reminder="; write( os, r.reminder );

    return os;
}

std::ostream & write( std::ostream & os, const AddReminderResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " job_id="; write( os, r.job_id );

    return os;
}

std::ostream & write( std::ostream & os, const ModifyReminderRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " job_id="; write( os, r.job_id );
    os << " contact_phone_id="; write( os, r.contact_phone_id );
    os << " reminder="; write( os, r.reminder );

    return os;
}

std::ostream & write( std::ostream & os, const ModifyReminderResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const GetReminderRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " job_id="; write( os, r.job_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetReminderResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " contact_id="; write( os, r.contact_id );
    os << " contact_phone_id="; write( os, r.contact_phone_id );
    os << " contact_phone="; write( os, r.contact_phone );
    os << " reminder="; write( os, r.reminder );

    return os;
}

std::ostream & write( std::ostream & os, const GetReminderStatusRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " user_id="; write( os, r.user_id );
    os << " search_filter="; write( os, r.search_filter );
    os << " effective_date_time_range="; ::basic_objects::str_helper::write( os, r.effective_date_time_range );
    os << " page_size="; write( os, r.page_size );
    os << " page_number="; write( os, r.page_number );

    return os;
}

} // namespace str_helper

} // namespace persek_protocol

