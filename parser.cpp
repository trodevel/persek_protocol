// system includes
#include <map>
#include <memory>

// includes
#include "parser.h"
#include "generic_protocol/parser.h"
#include "basic_objects/parser.h"
#include "dtmf_tools_protocol/parser.h"
#include "lang_tools_protocol/parser.h"
#include "basic_parser/parser.h"
#include "basic_parser/malformed_request.h"
#include "validator.h"
#include "request_type_parser.h"

namespace persek_protocol
{

namespace parser
{

using ::basic_parser::parser::get_value_or_throw;
using ::basic_parser::parser::get_value_or_throw_t;

// enums

void get_value_or_throw( voice_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<voice_e>( res_i );
}

void get_value_or_throw( urgency_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<urgency_e>( res_i );
}

void get_value_or_throw( JobInfo_type_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<JobInfo_type_e>( res_i );
}

void get_value_or_throw( exit_status_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<exit_status_e>( res_i );
}

void get_value_or_throw( OpenJobStatus_state_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<OpenJobStatus_state_e>( res_i );
}

void get_value_or_throw( FindJobRequest_status_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<FindJobRequest_status_e>( res_i );
}

void get_value_or_throw( action_type_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<action_type_e>( res_i );
}

void get_value_or_throw( ContactPhone_type_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<ContactPhone_type_e>( res_i );
}

void get_value_or_throw( gender_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<gender_e>( res_i );
}

void get_value_or_throw( ReminderAction_type_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<ReminderAction_type_e>( res_i );
}

// objects

void get_value_or_throw( JobOptions * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->voice, prefix + ".VOICE", r );
    get_value_or_throw( & res->urgency, prefix + ".URGENCY", r );
    ::lang_tools::parser::get_value_or_throw( & res->lang, prefix + ".LANG", r );
    get_value_or_throw( & res->exec_time, prefix + ".EXEC_TIME", r );
    get_value_or_throw( & res->max_tries, prefix + ".MAX_TRIES", r );
    get_value_or_throw( & res->redial_if_no_feedback, prefix + ".REDIAL_IF_NO_FEEDBACK", r );
    ::basic_objects::parser::get_value_or_throw( & res->time_window, prefix + ".TIME_WINDOW", r );
    ::basic_objects::parser::get_value_or_throw( & res->weekdays_mask, prefix + ".WEEKDAYS_MASK", r );
}

void get_value_or_throw( JobInfo * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->job_id, prefix + ".JOB_ID", r );
    get_value_or_throw( & res->user_id, prefix + ".USER_ID", r );
    get_value_or_throw( & res->type, prefix + ".TYPE", r );
    get_value_or_throw( & res->contact, prefix + ".CONTACT", r );
    get_value_or_throw( & res->creation_time, prefix + ".CREATION_TIME", r );
    get_value_or_throw( & res->options, prefix + ".OPTIONS", r );
}

void get_value_or_throw( ClosedJobStatus * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->job_id, prefix + ".JOB_ID", r );
    get_value_or_throw( & res->exit_code, prefix + ".EXIT_CODE", r );
    get_value_or_throw_t( & res->feedback, prefix + ".FEEDBACK", r, static_cast<void (*)( uint32_t * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
    get_value_or_throw( & res->num_tries, prefix + ".NUM_TRIES", r );
    get_value_or_throw( & res->timestamp, prefix + ".TIMESTAMP", r );
    get_value_or_throw( & res->comment, prefix + ".COMMENT", r );
}

void get_value_or_throw( OpenJobStatus * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->job_id, prefix + ".JOB_ID", r );
    get_value_or_throw( & res->state, prefix + ".STATE", r );
    get_value_or_throw( & res->current_try, prefix + ".CURRENT_TRY", r );
    get_value_or_throw( & res->timestamp, prefix + ".TIMESTAMP", r );
    get_value_or_throw( & res->next_exec_time, prefix + ".NEXT_EXEC_TIME", r );
}

void get_value_or_throw( TemplateInfo * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->id, prefix + ".ID", r );
    get_value_or_throw( & res->category_id, prefix + ".CATEGORY_ID", r );
    get_value_or_throw( & res->name, prefix + ".NAME", r );
    ::lang_tools::parser::get_value_or_throw( & res->lang, prefix + ".LANG", r );
    get_value_or_throw( & res->localized_name, prefix + ".LOCALIZED_NAME", r );
    get_value_or_throw_t( & res->placeholders, prefix + ".PLACEHOLDERS", r, static_cast<void (*)( std::string * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( CancellationFailureReason * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->job_id, prefix + ".JOB_ID", r );
    ::generic_protocol::parser::get_value_or_throw( & res->type, prefix + ".TYPE", r );
    get_value_or_throw( & res->descr, prefix + ".DESCR", r );
}

void get_value_or_throw( Action * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->type, prefix + ".TYPE", r );
    get_value_or_throw( & res->msg_templ_id, prefix + ".MSG_TEMPL_ID", r );
}

void get_value_or_throw( ContactPhone * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->type, prefix + ".TYPE", r );
    get_value_or_throw( & res->phone_number, prefix + ".PHONE_NUMBER", r );
}

void get_value_or_throw( ContactPhoneWithId * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->contact_phone_id, prefix + ".CONTACT_PHONE_ID", r );
    get_value_or_throw( & res->contact_phone, prefix + ".CONTACT_PHONE", r );
}

void get_value_or_throw( Contact * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->gender, prefix + ".GENDER", r );
    get_value_or_throw( & res->name, prefix + ".NAME", r );
    get_value_or_throw( & res->first_name, prefix + ".FIRST_NAME", r );
    ::basic_objects::parser::get_value_or_throw( & res->birthday, prefix + ".BIRTHDAY", r );
    get_value_or_throw( & res->notice, prefix + ".NOTICE", r );
}

void get_value_or_throw( ExtendedContactInfo * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->voice, prefix + ".VOICE", r );
    ::lang_tools::parser::get_value_or_throw( & res->lang, prefix + ".LANG", r );
    get_value_or_throw( & res->max_tries, prefix + ".MAX_TRIES", r );
    get_value_or_throw( & res->redial_if_no_feedback, prefix + ".REDIAL_IF_NO_FEEDBACK", r );
    ::basic_objects::parser::get_value_or_throw( & res->time_window, prefix + ".TIME_WINDOW", r );
    ::basic_objects::parser::get_value_or_throw( & res->weekdays, prefix + ".WEEKDAYS", r );
}

void get_value_or_throw( ReminderAction * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->type, prefix + ".TYPE", r );
    get_value_or_throw( & res->msg_templ_id, prefix + ".MSG_TEMPL_ID", r );
}

void get_value_or_throw( ReminderOptions * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->voice, prefix + ".VOICE", r );
    ::lang_tools::parser::get_value_or_throw( & res->lang, prefix + ".LANG", r );
    get_value_or_throw( & res->max_tries, prefix + ".MAX_TRIES", r );
    get_value_or_throw( & res->redial_if_no_feedback, prefix + ".REDIAL_IF_NO_FEEDBACK", r );
    ::basic_objects::parser::get_value_or_throw( & res->time_window, prefix + ".TIME_WINDOW", r );
    ::basic_objects::parser::get_value_or_throw( & res->weekdays, prefix + ".WEEKDAYS", r );
}

void get_value_or_throw( Reminder * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->msg_templ_id, prefix + ".MSG_TEMPL_ID", r );
    get_value_or_throw( & res->feedback_templ_id, prefix + ".FEEDBACK_TEMPL_ID", r );
    get_value_or_throw( & res->effective_time, prefix + ".EFFECTIVE_TIME", r );
    get_value_or_throw( & res->remind_period, prefix + ".REMIND_PERIOD", r );
    get_value_or_throw_t( & res->params, prefix + ".PARAMS", r, static_cast<void (*)( std::string * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ), static_cast<void (*)( std::string * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Map
    get_value_or_throw_t( & res->actions, prefix + ".ACTIONS", r, static_cast<void (*)( dtmf_tools::tone_e * , const std::string & , const generic_request::Request & )>( &::dtmf_tools::parser::get_value_or_throw ), static_cast<void (*)( ReminderAction * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Map
    get_value_or_throw( & res->options, prefix + ".OPTIONS", r );
}

// base messages

void get_value_or_throw( Request * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::Request*>( res ), r );

}

void get_value_or_throw( BackwardMessage * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

}

// messages

void get_value_or_throw( GetJobInfoRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
    get_value_or_throw_t( & res->job_ids, "JOB_IDS", r, static_cast<void (*)( uint32_t * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( GetJobInfoResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw_t( & res->jobs, "JOBS", r, static_cast<void (*)( JobInfo * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( GetJobStatRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
    get_value_or_throw_t( & res->job_ids, "JOB_IDS", r, static_cast<void (*)( uint32_t * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( GetJobStatResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw_t( & res->open_jobs, "OPEN_JOBS", r, static_cast<void (*)( OpenJobStatus * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
    get_value_or_throw_t( & res->closed_jobs, "CLOSED_JOBS", r, static_cast<void (*)( ClosedJobStatus * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( FindJobRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
    get_value_or_throw( & res->status, "STATUS", r );
    get_value_or_throw( & res->contact_regex, "CONTACT_REGEX", r );
    ::basic_objects::parser::get_value_or_throw( & res->creation_time_range, "CREATION_TIME_RANGE", r );
    ::basic_objects::parser::get_value_or_throw( & res->exec_time_range, "EXEC_TIME_RANGE", r );
    ::basic_objects::parser::get_value_or_throw( & res->update_time_range, "UPDATE_TIME_RANGE", r );
    get_value_or_throw( & res->max_results, "MAX_RESULTS", r );
    get_value_or_throw( & res->offset, "OFFSET", r );
}

void get_value_or_throw( FindJobResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->total_size, "TOTAL_SIZE", r );
    get_value_or_throw_t( & res->job_ids, "JOB_IDS", r, static_cast<void (*)( uint32_t * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( FindTemplatesRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
    get_value_or_throw( & res->category_id, "CATEGORY_ID", r );
    get_value_or_throw( & res->name_regex, "NAME_REGEX", r );
    ::lang_tools::parser::get_value_or_throw( & res->lang, "LANG", r );
}

void get_value_or_throw( FindTemplatesResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw_t( & res->templates, "TEMPLATES", r, static_cast<void (*)( TemplateInfo * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( CancelJobRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->job_id, "JOB_ID", r );
}

void get_value_or_throw( CancelJobResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

}

void get_value_or_throw( CancelJobsRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw_t( & res->job_ids, "JOB_IDS", r, static_cast<void (*)( uint32_t * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( CancelJobsResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw_t( & res->cancelled_job_ids, "CANCELLED_JOB_IDS", r, static_cast<void (*)( uint32_t * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
    get_value_or_throw_t( & res->failed_jobs, "FAILED_JOBS", r, static_cast<void (*)( CancellationFailureReason * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( SayRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
    get_value_or_throw( & res->contact_id, "CONTACT_ID", r );
    get_value_or_throw( & res->msg_templ_id, "MSG_TEMPL_ID", r );
    get_value_or_throw_t( & res->params, "PARAMS", r, static_cast<void (*)( std::string * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ), static_cast<void (*)( std::string * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Map
    get_value_or_throw( & res->options, "OPTIONS", r );
}

void get_value_or_throw( SayResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->job_id, "JOB_ID", r );
}

void get_value_or_throw( SayFeedbackRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
    get_value_or_throw( & res->contact_id, "CONTACT_ID", r );
    get_value_or_throw( & res->msg_templ_id, "MSG_TEMPL_ID", r );
    get_value_or_throw( & res->feedback_templ_id, "FEEDBACK_TEMPL_ID", r );
    get_value_or_throw_t( & res->params, "PARAMS", r, static_cast<void (*)( std::string * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ), static_cast<void (*)( std::string * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Map
    get_value_or_throw_t( & res->actions, "ACTIONS", r, static_cast<void (*)( dtmf_tools::tone_e * , const std::string & , const generic_request::Request & )>( &::dtmf_tools::parser::get_value_or_throw ), static_cast<void (*)( Action * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Map
    get_value_or_throw( & res->options, "OPTIONS", r );
}

void get_value_or_throw( SayFeedbackResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->job_id, "JOB_ID", r );
}

void get_value_or_throw( AddContactPhoneRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->contact_id, "CONTACT_ID", r );
    get_value_or_throw( & res->contact_phone, "CONTACT_PHONE", r );
}

void get_value_or_throw( AddContactPhoneResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->contact_phone_id, "CONTACT_PHONE_ID", r );
}

void get_value_or_throw( ModifyContactPhoneRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->contact_phone_id, "CONTACT_PHONE_ID", r );
    get_value_or_throw( & res->contact_phone, "CONTACT_PHONE", r );
}

void get_value_or_throw( ModifyContactPhoneResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

}

void get_value_or_throw( DeleteContactPhoneRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->contact_phone_id, "CONTACT_PHONE_ID", r );
}

void get_value_or_throw( DeleteContactPhoneResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

}

void get_value_or_throw( GetContactPhoneRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->contact_phone_id, "CONTACT_PHONE_ID", r );
}

void get_value_or_throw( GetContactPhoneResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->contact_id, "CONTACT_ID", r );
    get_value_or_throw( & res->contact_phone, "CONTACT_PHONE", r );
}

void get_value_or_throw( AddContactRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
    get_value_or_throw( & res->contact, "CONTACT", r );
}

void get_value_or_throw( AddContactResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->contact_id, "CONTACT_ID", r );
}

void get_value_or_throw( ModifyContactRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->contact_id, "CONTACT_ID", r );
    get_value_or_throw( & res->contact, "CONTACT", r );
}

void get_value_or_throw( ModifyContactResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

}

void get_value_or_throw( DeleteContactRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->contact_id, "CONTACT_ID", r );
}

void get_value_or_throw( DeleteContactResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

}

void get_value_or_throw( GetContactRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->contact_id, "CONTACT_ID", r );
}

void get_value_or_throw( GetContactResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->contact, "CONTACT", r );
    get_value_or_throw_t( & res->contact_phone_ids, "CONTACT_PHONE_IDS", r, static_cast<void (*)( uint32_t * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( GetContactWithPhonesRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->contact_id, "CONTACT_ID", r );
}

void get_value_or_throw( GetContactWithPhonesResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->contact, "CONTACT", r );
    get_value_or_throw_t( & res->contact_phones, "CONTACT_PHONES", r, static_cast<void (*)( ContactPhoneWithId * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( GetContactExtRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->contact_id, "CONTACT_ID", r );
}

void get_value_or_throw( GetContactExtResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->contact, "CONTACT", r );
    get_value_or_throw_t( & res->contact_phones, "CONTACT_PHONES", r, static_cast<void (*)( ContactPhoneWithId * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
    get_value_or_throw( & res->extended_info, "EXTENDED_INFO", r );
}

void get_value_or_throw( GetExtendedContactInfoRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->contact_id, "CONTACT_ID", r );
}

void get_value_or_throw( GetExtendedContactInfoResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->extended_info, "EXTENDED_INFO", r );
}

void get_value_or_throw( SetExtendedContactInfoRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->contact_id, "CONTACT_ID", r );
    get_value_or_throw( & res->extended_info, "EXTENDED_INFO", r );
}

void get_value_or_throw( SetExtendedContactInfoResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

}

void get_value_or_throw( AddReminderRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->contact_phone_id, "CONTACT_PHONE_ID", r );
    get_value_or_throw( & res->reminder, "REMINDER", r );
}

void get_value_or_throw( AddReminderResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->job_id, "JOB_ID", r );
}

void get_value_or_throw( ModifyReminderRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->job_id, "JOB_ID", r );
    get_value_or_throw( & res->contact_phone_id, "CONTACT_PHONE_ID", r );
    get_value_or_throw( & res->reminder, "REMINDER", r );
}

void get_value_or_throw( ModifyReminderResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

}

void get_value_or_throw( GetReminderRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->job_id, "JOB_ID", r );
}

void get_value_or_throw( GetReminderResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->contact_id, "CONTACT_ID", r );
    get_value_or_throw( & res->contact_phone_id, "CONTACT_PHONE_ID", r );
    get_value_or_throw( & res->contact_phone, "CONTACT_PHONE", r );
    get_value_or_throw( & res->reminder, "REMINDER", r );
}

void get_value_or_throw( GetReminderStatusRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
    get_value_or_throw( & res->search_filter, "SEARCH_FILTER", r );
    ::basic_objects::parser::get_value_or_throw( & res->effective_date_time_range, "EFFECTIVE_DATE_TIME_RANGE", r );
    get_value_or_throw( & res->page_size, "PAGE_SIZE", r );
    get_value_or_throw( & res->page_number, "PAGE_NUMBER", r );
}

// to object

Object * to_GetJobInfoRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetJobInfoRequest> res( new GetJobInfoRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetJobInfoResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetJobInfoResponse> res( new GetJobInfoResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetJobStatRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetJobStatRequest> res( new GetJobStatRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetJobStatResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetJobStatResponse> res( new GetJobStatResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_FindJobRequest( const generic_request::Request & r )
{
    std::unique_ptr<FindJobRequest> res( new FindJobRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_FindJobResponse( const generic_request::Request & r )
{
    std::unique_ptr<FindJobResponse> res( new FindJobResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_FindTemplatesRequest( const generic_request::Request & r )
{
    std::unique_ptr<FindTemplatesRequest> res( new FindTemplatesRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_FindTemplatesResponse( const generic_request::Request & r )
{
    std::unique_ptr<FindTemplatesResponse> res( new FindTemplatesResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_CancelJobRequest( const generic_request::Request & r )
{
    std::unique_ptr<CancelJobRequest> res( new CancelJobRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_CancelJobResponse( const generic_request::Request & r )
{
    std::unique_ptr<CancelJobResponse> res( new CancelJobResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_CancelJobsRequest( const generic_request::Request & r )
{
    std::unique_ptr<CancelJobsRequest> res( new CancelJobsRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_CancelJobsResponse( const generic_request::Request & r )
{
    std::unique_ptr<CancelJobsResponse> res( new CancelJobsResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_SayRequest( const generic_request::Request & r )
{
    std::unique_ptr<SayRequest> res( new SayRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_SayResponse( const generic_request::Request & r )
{
    std::unique_ptr<SayResponse> res( new SayResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_SayFeedbackRequest( const generic_request::Request & r )
{
    std::unique_ptr<SayFeedbackRequest> res( new SayFeedbackRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_SayFeedbackResponse( const generic_request::Request & r )
{
    std::unique_ptr<SayFeedbackResponse> res( new SayFeedbackResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_AddContactPhoneRequest( const generic_request::Request & r )
{
    std::unique_ptr<AddContactPhoneRequest> res( new AddContactPhoneRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_AddContactPhoneResponse( const generic_request::Request & r )
{
    std::unique_ptr<AddContactPhoneResponse> res( new AddContactPhoneResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_ModifyContactPhoneRequest( const generic_request::Request & r )
{
    std::unique_ptr<ModifyContactPhoneRequest> res( new ModifyContactPhoneRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_ModifyContactPhoneResponse( const generic_request::Request & r )
{
    std::unique_ptr<ModifyContactPhoneResponse> res( new ModifyContactPhoneResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_DeleteContactPhoneRequest( const generic_request::Request & r )
{
    std::unique_ptr<DeleteContactPhoneRequest> res( new DeleteContactPhoneRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_DeleteContactPhoneResponse( const generic_request::Request & r )
{
    std::unique_ptr<DeleteContactPhoneResponse> res( new DeleteContactPhoneResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetContactPhoneRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetContactPhoneRequest> res( new GetContactPhoneRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetContactPhoneResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetContactPhoneResponse> res( new GetContactPhoneResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_AddContactRequest( const generic_request::Request & r )
{
    std::unique_ptr<AddContactRequest> res( new AddContactRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_AddContactResponse( const generic_request::Request & r )
{
    std::unique_ptr<AddContactResponse> res( new AddContactResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_ModifyContactRequest( const generic_request::Request & r )
{
    std::unique_ptr<ModifyContactRequest> res( new ModifyContactRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_ModifyContactResponse( const generic_request::Request & r )
{
    std::unique_ptr<ModifyContactResponse> res( new ModifyContactResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_DeleteContactRequest( const generic_request::Request & r )
{
    std::unique_ptr<DeleteContactRequest> res( new DeleteContactRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_DeleteContactResponse( const generic_request::Request & r )
{
    std::unique_ptr<DeleteContactResponse> res( new DeleteContactResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetContactRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetContactRequest> res( new GetContactRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetContactResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetContactResponse> res( new GetContactResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetContactWithPhonesRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetContactWithPhonesRequest> res( new GetContactWithPhonesRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetContactWithPhonesResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetContactWithPhonesResponse> res( new GetContactWithPhonesResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetContactExtRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetContactExtRequest> res( new GetContactExtRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetContactExtResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetContactExtResponse> res( new GetContactExtResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetExtendedContactInfoRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetExtendedContactInfoRequest> res( new GetExtendedContactInfoRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetExtendedContactInfoResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetExtendedContactInfoResponse> res( new GetExtendedContactInfoResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_SetExtendedContactInfoRequest( const generic_request::Request & r )
{
    std::unique_ptr<SetExtendedContactInfoRequest> res( new SetExtendedContactInfoRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_SetExtendedContactInfoResponse( const generic_request::Request & r )
{
    std::unique_ptr<SetExtendedContactInfoResponse> res( new SetExtendedContactInfoResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_AddReminderRequest( const generic_request::Request & r )
{
    std::unique_ptr<AddReminderRequest> res( new AddReminderRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_AddReminderResponse( const generic_request::Request & r )
{
    std::unique_ptr<AddReminderResponse> res( new AddReminderResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_ModifyReminderRequest( const generic_request::Request & r )
{
    std::unique_ptr<ModifyReminderRequest> res( new ModifyReminderRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_ModifyReminderResponse( const generic_request::Request & r )
{
    std::unique_ptr<ModifyReminderResponse> res( new ModifyReminderResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetReminderRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetReminderRequest> res( new GetReminderRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetReminderResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetReminderResponse> res( new GetReminderResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetReminderStatusRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetReminderStatusRequest> res( new GetReminderStatusRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

// to forward message

basic_parser::Object* to_forward_message( const generic_request::Request & r )
{
    auto type = detect_request_type( r );

    typedef request_type_e KeyType;

    typedef Object* (*PPMF)( const generic_request::Request & r );

#define HANDLER_MAP_ENTRY(_v)       { KeyType::_v,    & to_##_v }

    static const std::map<KeyType, PPMF> funcs =
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

    auto it = funcs.find( type );

    if( it != funcs.end() )
        return it->second( r );

    return generic_protocol::parser::to_forward_message( r );
}

using basic_parser::MalformedRequest;

request_type_e  detect_request_type( const generic_request::Request & r )
{
    std::string cmd;

    if( r.get_value( "CMD", cmd ) == false )
        throw MalformedRequest( "CMD is not defined" );

    return RequestTypeParser::to_request_type( cmd );
}

} // namespace parser

} // namespace persek_protocol

