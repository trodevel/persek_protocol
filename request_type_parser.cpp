// system includes
#include <map>

// includes
#include "request_type_parser.h"

namespace persek_protocol
{

#define TUPLE_VAL_STR(_x_)  _x_,"persek/"+std::string(#_x_)

template< typename _U, typename _V >
std::pair<_V,_U> make_inverse_pair( _U first, _V second )
{
    return std::make_pair( second, first );
}

request_type_e RequestTypeParser::to_request_type( const std::string & s )
{
    typedef std::string KeyType;
    typedef request_type_e Type;

    typedef std::map< KeyType, Type > Map;
    static const Map m =
    {
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetJobInfoRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetJobInfoResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetJobStatRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetJobStatResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( FindJobRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( FindJobResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( FindTemplatesRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( FindTemplatesResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( CancelJobRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( CancelJobResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( CancelJobsRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( CancelJobsResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( SayRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( SayResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( SayFeedbackRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( SayFeedbackResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( AddContactPhoneRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( AddContactPhoneResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( ModifyContactPhoneRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( ModifyContactPhoneResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( DeleteContactPhoneRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( DeleteContactPhoneResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetContactPhoneRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetContactPhoneResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( AddContactRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( AddContactResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( ModifyContactRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( ModifyContactResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( DeleteContactRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( DeleteContactResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetContactRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetContactResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetContactWithPhonesRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetContactWithPhonesResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetContactExtRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetContactExtResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetExtendedContactInfoRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetExtendedContactInfoResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( SetExtendedContactInfoRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( SetExtendedContactInfoResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( AddReminderRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( AddReminderResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( ModifyReminderRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( ModifyReminderResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetReminderRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetReminderResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetReminderStatusRequest ) ),
    };

    auto it = m.find( s );

    if( it == m.end() )
        return request_type_e::UNDEF;

    return it->second;
}
} // namespace persek_protocol

