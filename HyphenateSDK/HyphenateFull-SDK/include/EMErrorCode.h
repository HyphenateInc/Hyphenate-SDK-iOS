/*!
 *  @header EMErrorCode.h
 *  @abstract SDK defined error type
 *  @author Hyphenate
 *  @version 3.00
 */

typedef enum{

    EMErrorGeneral = 1,                      /*! General error */
    EMErrorNetworkUnavailable,               /*! Network is unavaliable */
    
    EMErrorInvalidAppkey = 100,              /*! App key is invalid */
    EMErrorInvalidUsername,                  /*! User name is invalid */
    EMErrorInvalidPassword,                  /*! Password is invalid */
    EMErrorInvalidURL,                       /*! URL is invalid */
    
    EMErrorUserAlreadyLogin = 200,           /*! User has already logged in */
    EMErrorUserNotLogin,                     /*! User has not logged in */
    EMErrorUserAuthenticationFailed,         /*! Password check failed */
    EMErrorUserAlreadyExist,                 /*! User has already exist */
    EMErrorUserNotFound,                     /*! User was not found */
    EMErrorUserIllegalArgument,              /*! Illegal argument */
    EMErrorUserLoginOnAnotherDevice,         /*! User has logged in from another device */
    EMErrorUserRemoved,                      /*! User was removed from server */
    EMErrorUserRegisterFailed,               /*! Register user failed */
    EMErrorUpdateApnsConfigsFailed,          /*! Update apns configs failed */
    EMErrorUserPermissionDenied,             /*! User has no right for this operation. */
    
    EMErrorServerNotReachable = 300,         /*! Server is not reachable */
    EMErrorServerTimeout,                    /*! Wait server response timeout */
    EMErrorServerBusy,                       /*! Server is busy */
    EMErrorServerUnknownError,               /*! Unknown server error */
    
    EMErrorFileNotFound = 400,               /*! Can't find the file */
    EMErrorFileInvalid,                      /*! File is invalid */
    EMErrorFileUploadFailed,                 /*! Upload file failed */
    EMErrorFileDownloadFailed,               /*! Download file failed */
    
    EMErrorMessageInvalid = 500,             /*! Message is invalid */
    EMErrorMessageIncludeIllegalContent,     /*! Message contains illegal content */
    EMErrorMessageTrafficLimit,              /*! Unit time to send messages over the upper limit */
    EMErrorMessageEncryption,                /*! Encryption error */
    
    EMErrorGroupInvalidId = 600,             /*! Group Id is invalid */
    EMErrorGroupAlreadyJoined,               /*! User has already joined the group */
    EMErrorGroupNotJoined,                   /*! User has not joined the group */
    EMErrorGroupPermissionDenied,            /*! User has NO authority for the operation */
    EMErrorGroupMembersFull,                 /*! Reach group's max member count */
    EMErrorGroupNotExist,                    /*! Group is not exist */
    
    EMErrorChatroomInvalidId = 700,          /*! Chatroom id is invalid */
    EMErrorChatroomAlreadyJoined,            /*! User has already joined the chatroom */
    EMErrorChatroomNotJoined,                /*! User has not joined the chatroom */
    EMErrorChatroomPermissionDenied,         /*! User has NO authority for the operation */
    EMErrorChatroomMembersFull,              /*! Reach chatroom's max member count */
    EMErrorChatroomNotExist,                 /*! Chatroom is not exist */
    
    EMErrorCallInvalidId = 800,              /*! Call id is invalid */
    EMErrorCallBusy,                         /*! User is busy */
    EMErrorCallRemoteOffline,                /*! Callee is offline */
    EMErrorCallConnectFailed,                /*! Establish connection failed */

}EMErrorCode;
