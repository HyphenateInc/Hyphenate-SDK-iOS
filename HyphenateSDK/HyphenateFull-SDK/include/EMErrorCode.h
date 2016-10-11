/*!
 *  @header EMErrorCode.h
 *  @abstract SDK defined error type
 *  @author Hyphenate
 *  @version 3.00
 */

typedef enum{

    EMErrorGeneral = 1,                      /*!  General error */
    EMErrorNetworkUnavailable,               /*!  Network is unavaliable */
    EMErrorDatabaseOperationFailed,          /*!  Database operation failed */
    
    EMErrorInvalidAppkey = 100,              /*!  App key is invalid */
    EMErrorInvalidUsername,                  /*!  User name is invalid */
    EMErrorInvalidPassword,                  /*!  Password is invalid */
    EMErrorInvalidURL,                       /*!  URL is invalid */
    
    EMErrorUserAlreadyLogin = 200,           /*!  User has already logged in */
    EMErrorUserNotLogin,                     /*!  User has not logged in */
    EMErrorUserAuthenticationFailed,         /*!  Password authentication failed */
    EMErrorUserAlreadyExist,                 /*!  User has already existed */
    EMErrorUserNotFound,                     /*!  User was not found */
    EMErrorUserIllegalArgument,              /*!  Illegal argument */
    EMErrorUserLoginOnAnotherDevice,         /*!  User has logged in from another device */
    EMErrorUserRemoved,                      /*!  User was removed from server */
    EMErrorUserRegisterFailed,               /*!  Registration failed */
    EMErrorUpdateApnsConfigsFailed,          /*!  Update Apple Push Notification configurations failed */
    EMErrorUserPermissionDenied,             /*!  User has no access for this operation. */
    
    EMErrorServerNotReachable = 300,         /*!  Server is not reachable */
    EMErrorServerTimeout,                    /*!  Server response timeout */
    EMErrorServerBusy,                       /*!  Server is busy */
    EMErrorServerUnknownError,               /*!  Unknown server error */
    EMErrorServerGetDNSConfigFailed,         /*!  Get DNS config failure */
    
    EMErrorFileNotFound = 400,               /*!  Can't find the file */
    EMErrorFileInvalid,                      /*!  File is invalid */
    EMErrorFileUploadFailed,                 /*!  Upload file failure */
    EMErrorFileDownloadFailed,               /*!  Download file failed */
    
    EMErrorMessageInvalid = 500,             /*!  Message is invalid */
    EMErrorMessageIncludeIllegalContent,      /*!  Message contains illegal content */
    EMErrorMessageTrafficLimit,              /*!  Unit time to send messages over the upper limit */
    EMErrorMessageEncryption,                /*!  Encryption error */
    
    EMErrorGroupInvalidId = 600,             /*!  Group Id is invalid */
    EMErrorGroupAlreadyJoined,               /*!  User has already joined the group */
    EMErrorGroupNotJoined,                   /*!  User has not joined the group */
    EMErrorGroupPermissionDenied,            /*!  User has no access for the operation */
    EMErrorGroupMembersFull,                 /*!  Reach group's max member count */
    EMErrorGroupNotExist,                    /*!  Group is not existed */
    
    EMErrorChatroomInvalidId = 700,          /*!  Chatroom id is invalid */
    EMErrorChatroomAlreadyJoined,            /*!  User has already joined the chatroom */
    EMErrorChatroomNotJoined,                /*!  User has not joined the chatroom */
    EMErrorChatroomPermissionDenied,         /*!  User has no access for the operation */
    EMErrorChatroomMembersFull,              /*!  Reach chatroom's capacity */
    EMErrorChatroomNotExist,                 /*!  Chatroom is not existed */
    
    EMErrorCallInvalidId = 800,              /*!  Call id is invalid */
    EMErrorCallBusy,                         /*!  User is busy */
    EMErrorCallRemoteOffline,                /*!  Callee is offline */
    EMErrorCallConnectFailed,                /*!  Establish connection failure */

}EMErrorCode;
