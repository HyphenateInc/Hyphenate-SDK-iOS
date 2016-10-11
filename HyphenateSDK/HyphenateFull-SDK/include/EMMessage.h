/*!
 *  @header EMMessage.h
 *  @abstract Chat message
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMMessageBody.h"

/*!
 *  Chat type
 */
typedef enum{
    EMChatTypeChat   = 0,   /*!  one to one chat type */
    EMChatTypeGroupChat,    /*!  Group chat type */
    EMChatTypeChatRoom,     /*!  Chatroom chat type */
}EMChatType;

/*!
 *   Message Status
 */
typedef enum{
    EMMessageStatusPending  = 0,    /*!  Pending */
    EMMessageStatusDelivering,      /*!  Delivering */
    EMMessageStatusSuccessed,       /*!  Successed */
    EMMessageStatusFailed,          /*!  Failed */
}EMMessageStatus;

/*!
 *  Message direction
 */
typedef enum{
    EMMessageDirectionSend = 0,    /*!  Send */
    EMMessageDirectionReceive,     /*!  Receive */
}EMMessageDirection;

/*!
 *  Chat message
 */
@interface EMMessage : NSObject

/*!
 *  Unique identifier of message
 */
@property (nonatomic, copy) NSString *messageId;

/*!
 *  Unique identifier of message's conversation
 */
@property (nonatomic, copy) NSString *conversationId;

/*!
 *  Message direction
 */
@property (nonatomic) EMMessageDirection direction;

/*!
 *  Message sender
 */
@property (nonatomic, copy) NSString *from;

/*!
 *  Message receiver
 */
@property (nonatomic, copy) NSString *to;

/*!
 *  Timestamp, the time of server received this message
 */
@property (nonatomic) long long timestamp;

/*!
 *  The time of client send/receive the message
 */
@property (nonatomic) long long localTime;

/*!
 *  Chat type
 */
@property (nonatomic) EMChatType chatType;

/*!
 *  Message status
 */
@property (nonatomic) EMMessageStatus status;

/*!
 *  Whether read acknowledgement has been sent or received, it indicates whether the sender has received a message read acknowledgement, or whether the recipient has sent a message read acknowledgement
 */
@property (nonatomic) BOOL isReadAcked;

/*!
 *  Whether delivery acknowledgement has been sent or received, it indicates whether the sender has received a message deliver acknowledgement, or whether the recipient has sent a message deliver acknowledgement, SDK will automatically send delivery acknowledgement if EMOptions is set to enableDeliveryAck
 */
@property (nonatomic) BOOL isDeliverAcked;

/*!
 *  Whether the message has been read
 */
@property (nonatomic) BOOL isRead;

/*!
 *  Message body
 */
@property (nonatomic, strong) EMMessageBody *body;

/*!
 *  Message extention
 *
 *  Key type must be NSString, Value type must be NSString, int, unsigned in, long long, or double. Please use NSNumber (@YES or @NO) instead of BOOL.
 */
@property (nonatomic, copy) NSDictionary *ext;

/*!
 *  Initialize a message instance
 *
 *  @param aConversationId  Conversation id
 *  @param aFrom            The sender
 *  @param aTo              The receiver
 *  @param aBody            Message body
 *  @param aExt             Message extention
 *
 *  @result Message instance
 */
- (id)initWithConversationID:(NSString *)aConversationId
                        from:(NSString *)aFrom
                          to:(NSString *)aTo
                        body:(EMMessageBody *)aBody
                         ext:(NSDictionary *)aExt;


@end
