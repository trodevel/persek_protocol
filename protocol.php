<?php

namespace persek_protocol;


// includes
require_once __DIR__.'/../basic_parser/object.php';
require_once __DIR__.'/../generic_protocol/protocol.php';

// includes for used modules
require_once __DIR__.'/../basic_objects/protocol.php';
require_once __DIR__.'/../dtmf_tools/protocol.php';
require_once __DIR__.'/../lang_tools/protocol.php';

// Enum voice_e
const voice_e__UNDEF                = 0;
const voice_e__MALE_A               = 1;
const voice_e__FEMALE_A             = 2;

// Enum urgency_e
const urgency_e__UNDEF                = 0;
const urgency_e__IMMEDIATE            = 1;
const urgency_e__TIMED                = 2;

// Enum JobInfo_type_e
const JobInfo_type_e__UNDEF                = 0;
const JobInfo_type_e__SAY                  = 1;
const JobInfo_type_e__SAY_FEEDBACK         = 2;
const JobInfo_type_e__FSM                  = 3;
const JobInfo_type_e__REMINDER             = 4;

// Enum exit_status_e
const exit_status_e__DONE                 = 0;
const exit_status_e__CANCELLED            = 0;
const exit_status_e__FAILED               = 0;
const exit_status_e__REFUSED_BY_RECIPIENT = 0;
const exit_status_e__ABORTED_BY_RECIPIENT = 0;

// Enum OpenJobStatus_state_e
const OpenJobStatus_state_e__IDLE                 = 1;
const OpenJobStatus_state_e__WAITING_PROC_STARTED = 2;
const OpenJobStatus_state_e__ACTIVE               = 3;
const OpenJobStatus_state_e__WRONG_ACTIVE         = 4;
const OpenJobStatus_state_e__CANCELLED_IN_A       = 5;
const OpenJobStatus_state_e__CANCELLED_IN_WPS     = 6;
const OpenJobStatus_state_e__COMPLETED            = 7;
const OpenJobStatus_state_e__WAITING_REDIAL_TIMER = 8;

// Enum FindJobRequest_status_e
const FindJobRequest_status_e__ANY                  = 0;
const FindJobRequest_status_e__OPEN                 = 1;
const FindJobRequest_status_e__CLOSED               = 2;

// Enum action_type_e
const action_type_e__NONE                 = 0;
const action_type_e__REPEAT               = 1;
const action_type_e__DROP                 = 2;

// Enum ContactPhone_type_e
const ContactPhone_type_e__DFLT                 = 0;
const ContactPhone_type_e__LANDLINE             = 1;
const ContactPhone_type_e__MOBILE               = 2;

// Enum gender_e
const gender_e__UNDEF                = 0;
const gender_e__MALE                 = 1;
const gender_e__FEMALE               = 2;

// Enum ReminderAction_type_e
const ReminderAction_type_e__NONE                 = 0;
const ReminderAction_type_e__REPEAT               = 1;
const ReminderAction_type_e__DROP_FEEDBACK        = 2;
const ReminderAction_type_e__DROP_SNOOZE          = 3;

// Object
class JobOptions
{
    public $voice               ; // type: voice_e
    public $urgency             ; // type: urgency_e
    public $lang                ; // type: lang_tools\lang_e
    public $exec_time           ; // type: uint32_t
    public $max_tries           ; // type: uint32_t
    public $redial_if_no_feedback; // type: bool
    public $time_window         ; // type: basic_objects\TimeWindow
    public $weekdays_mask       ; // type: basic_objects\Weekdays
};

// Object
class JobInfo
{
    public $job_id              ; // type: uint32_t
    public $user_id             ; // type: uint32_t
    public $type                ; // type: JobInfo_type_e
    public $contact             ; // type: string
    public $creation_time       ; // type: uint32_t
    public $options             ; // type: JobOptions
};

// Object
class ClosedJobStatus
{
    public $job_id              ; // type: uint32_t
    public $exit_code           ; // type: exit_status_e
    public $feedback            ; // type: array<uint32_t>
    public $num_tries           ; // type: uint32_t
    public $timestamp           ; // type: uint32_t
    public $comment             ; // type: string
};

// Object
class OpenJobStatus
{
    public $job_id              ; // type: uint32_t
    public $state               ; // type: OpenJobStatus_state_e
    public $current_try         ; // type: uint32_t
    public $timestamp           ; // type: uint32_t
    public $next_exec_time      ; // type: uint32_t
};

// Object
class TemplateInfo
{
    public $id                  ; // type: uint32_t
    public $category_id         ; // type: uint32_t
    public $name                ; // type: string
    public $lang                ; // type: lang_tools\lang_e
    public $localized_name      ; // type: string
    public $placeholders        ; // type: array<string>
};

// Object
class CancellationFailureReason
{
    public $job_id              ; // type: uint32_t
    public $type                ; // type: generic_protocol\ErrorResponse_type_e
    public $descr               ; // type: string
};

// Object
class Action
{
    public $type                ; // type: action_type_e
    public $msg_templ_id        ; // type: uint32_t
};

// Object
class ContactPhone
{
    public $type                ; // type: ContactPhone_type_e
    public $phone_number        ; // type: string
};

// Object
class ContactPhoneWithId
{
    public $contact_phone_id    ; // type: uint32_t
    public $contact_phone       ; // type: ContactPhone
};

// Object
class Contact
{
    public $gender              ; // type: gender_e
    public $name                ; // type: string
    public $first_name          ; // type: string
    public $birthday            ; // type: basic_objects\Date
    public $notice              ; // type: string
};

// Object
class ExtendedContactInfo
{
    public $voice               ; // type: voice_e
    public $lang                ; // type: lang_tools\lang_e
    public $max_tries           ; // type: uint32_t
    public $redial_if_no_feedback; // type: bool
    public $time_window         ; // type: basic_objects\TimeWindow
    public $weekdays            ; // type: basic_objects\Weekdays
};

// Object
class ReminderAction
{
    public $type                ; // type: ReminderAction_type_e
    public $msg_templ_id        ; // type: uint32_t
};

// Object
class ReminderOptions
{
    public $voice               ; // type: voice_e
    public $lang                ; // type: lang_tools\lang_e
    public $max_tries           ; // type: uint32_t
    public $redial_if_no_feedback; // type: bool
    public $time_window         ; // type: basic_objects\TimeWindow
    public $weekdays            ; // type: basic_objects\Weekdays
};

// Object
class Reminder
{
    public $msg_templ_id        ; // type: uint32_t
    public $feedback_templ_id   ; // type: uint32_t
    public $effective_time      ; // type: uint32_t
    public $remind_period       ; // type: uint32_t
    public $params              ; // type: map<string, string>
    public $actions             ; // type: map<dtmf_tools\tone_e, ReminderAction>
    public $options             ; // type: ReminderOptions
};

// Base message
class Request extends \generic_protocol\Request
{
    function __construct()
    {
        parent::__construct();
    }
};

// Base message
class BackwardMessage extends \basic_parser\Object
{
    function __construct()
    {
    }
};

// Message
class GetJobInfoRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1271346161;

    public $user_id             ; // type: uint32_t
    public $job_ids             ; // type: array<uint32_t>
};

// Message
class GetJobInfoResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2483099416;

    public $jobs                ; // type: array<JobInfo>
};

// Message
class GetJobStatRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1923284523;

    public $user_id             ; // type: uint32_t
    public $job_ids             ; // type: array<uint32_t>
};

// Message
class GetJobStatResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 4064168223;

    public $open_jobs           ; // type: array<OpenJobStatus>
    public $closed_jobs         ; // type: array<ClosedJobStatus>
};

// Message
class FindJobRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3977482532;

    public $user_id             ; // type: uint32_t
    public $status              ; // type: FindJobRequest_status_e
    public $contact_regex       ; // type: string
    public $creation_time_range ; // type: basic_objects\TimeRange
    public $exec_time_range     ; // type: basic_objects\TimeRange
    public $update_time_range   ; // type: basic_objects\TimeRange
    public $max_results         ; // type: uint32_t
    public $offset              ; // type: uint32_t
};

// Message
class FindJobResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1646192097;

    public $total_size          ; // type: uint32_t
    public $job_ids             ; // type: array<uint32_t>
};

// Message
class FindTemplatesRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2884609259;

    public $user_id             ; // type: uint32_t
    public $category_id         ; // type: uint32_t
    public $name_regex          ; // type: string
    public $lang                ; // type: lang_tools\lang_e
};

// Message
class FindTemplatesResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1770243829;

    public $templates           ; // type: array<TemplateInfo>
};

// Message
class CancelJobRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2264595506;

    public $job_id              ; // type: uint32_t
};

// Message
class CancelJobResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2527181277;
};

// Message
class CancelJobsRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2132275223;

    public $job_ids             ; // type: array<uint32_t>
};

// Message
class CancelJobsResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3713826966;

    public $cancelled_job_ids   ; // type: array<uint32_t>
    public $failed_jobs         ; // type: array<CancellationFailureReason>
};

// Message
class SayRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2502716229;

    public $user_id             ; // type: uint32_t
    public $contact_id          ; // type: string
    public $msg_templ_id        ; // type: uint32_t
    public $params              ; // type: map<string, string>
    public $options             ; // type: JobOptions
};

// Message
class SayResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1490258901;

    public $job_id              ; // type: uint32_t
};

// Message
class SayFeedbackRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 4017966943;

    public $user_id             ; // type: uint32_t
    public $contact_id          ; // type: string
    public $msg_templ_id        ; // type: uint32_t
    public $feedback_templ_id   ; // type: uint32_t
    public $params              ; // type: map<string, string>
    public $actions             ; // type: map<dtmf_tools\tone_e, Action>
    public $options             ; // type: JobOptions
};

// Message
class SayFeedbackResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2781553547;

    public $job_id              ; // type: uint32_t
};

// Message
class AddContactPhoneRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 4289505603;

    public $contact_id          ; // type: uint32_t
    public $contact_phone       ; // type: ContactPhone
};

// Message
class AddContactPhoneResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2983898658;

    public $contact_phone_id    ; // type: uint32_t
};

// Message
class ModifyContactPhoneRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3445571302;

    public $contact_phone_id    ; // type: uint32_t
    public $contact_phone       ; // type: ContactPhone
};

// Message
class ModifyContactPhoneResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 391383762;
};

// Message
class DeleteContactPhoneRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 912440983;

    public $contact_phone_id    ; // type: uint32_t
};

// Message
class DeleteContactPhoneResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 816674552;
};

// Message
class GetContactPhoneRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 4064402296;

    public $contact_phone_id    ; // type: uint32_t
};

// Message
class GetContactPhoneResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 14461556;

    public $contact_id          ; // type: uint32_t
    public $contact_phone       ; // type: ContactPhone
};

// Message
class AddContactRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3558214978;

    public $user_id             ; // type: uint32_t
    public $contact             ; // type: Contact
};

// Message
class AddContactResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3338019856;

    public $contact_id          ; // type: uint32_t
};

// Message
class ModifyContactRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1830786728;

    public $contact_id          ; // type: uint32_t
    public $contact             ; // type: Contact
};

// Message
class ModifyContactResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2257594093;
};

// Message
class DeleteContactRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 183470883;

    public $contact_id          ; // type: uint32_t
};

// Message
class DeleteContactResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 4238183512;
};

// Message
class GetContactRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2569581716;

    public $contact_id          ; // type: uint32_t
};

// Message
class GetContactResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2836098376;

    public $contact             ; // type: Contact
    public $contact_phone_ids   ; // type: array<uint32_t>
};

// Message
class GetContactWithPhonesRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2810842599;

    public $contact_id          ; // type: uint32_t
};

// Message
class GetContactWithPhonesResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1614409591;

    public $contact             ; // type: Contact
    public $contact_phones      ; // type: array<ContactPhoneWithId>
};

// Message
class GetContactExtRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3042615038;

    public $contact_id          ; // type: uint32_t
};

// Message
class GetContactExtResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 71341860;

    public $contact             ; // type: Contact
    public $contact_phones      ; // type: array<ContactPhoneWithId>
    public $extended_info       ; // type: ExtendedContactInfo
};

// Message
class GetExtendedContactInfoRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 519081638;

    public $contact_id          ; // type: uint32_t
};

// Message
class GetExtendedContactInfoResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1633412338;

    public $extended_info       ; // type: ExtendedContactInfo
};

// Message
class SetExtendedContactInfoRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3478544754;

    public $contact_id          ; // type: uint32_t
    public $extended_info       ; // type: ExtendedContactInfo
};

// Message
class SetExtendedContactInfoResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3761525968;
};

// Message
class AddReminderRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 698796585;

    public $contact_phone_id    ; // type: uint32_t
    public $reminder            ; // type: Reminder
};

// Message
class AddReminderResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 476785671;

    public $job_id              ; // type: uint32_t
};

// Message
class ModifyReminderRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1774242004;

    public $job_id              ; // type: uint32_t
    public $contact_phone_id    ; // type: uint32_t
    public $reminder            ; // type: Reminder
};

// Message
class ModifyReminderResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3743925412;
};

// Message
class GetReminderRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1180402545;

    public $job_id              ; // type: uint32_t
};

// Message
class GetReminderResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2041841800;

    public $contact_id          ; // type: uint32_t
    public $contact_phone_id    ; // type: uint32_t
    public $contact_phone       ; // type: string
    public $reminder            ; // type: Reminder
};

// Message
class GetReminderStatusRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 962577539;

    public $user_id             ; // type: uint32_t
    public $search_filter       ; // type: string
    public $effective_date_time_range; // type: basic_objects\TimeRange
    public $page_size           ; // type: uint32_t
    public $page_number         ; // type: uint32_t
};

# namespace_end persek_protocol


?>

