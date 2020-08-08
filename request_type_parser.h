#ifndef APG_PERSEK__REQUEST_TYPE_PARSER_H
#define APG_PERSEK__REQUEST_TYPE_PARSER_H

// includes
#include "enums.h"

namespace persek_protocol
{

class RequestTypeParser
{
public:
    static request_type_e   to_request_type( const std::string & s );
};
} // namespace persek_protocol

#endif // APG_PERSEK__REQUEST_TYPE_PARSER_H
