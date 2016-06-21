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
    EMChatTypeChat   = 0,   /*! Chat */
    EMChatTypeGroupChat,    /*! Group chat */
    EMChatTypeChatRoom,     /*! Chatroom chat */
}EMChatType;

/*!
 *   Message Status
 */
typedef enum{
    EMMessageStatusPending  = 0,    /*! Pending */
    EMMessageStatusDelivering,      /*! Delivering */
    EMMessageStatusSuccessed,       /*! Successed */
    EMMessageStatusFailed,          /*! Failed */
}EMMessageStatus;

/*!
 *  Message direction
 */
typedef enum{
    EMMessageDirectionSend = 0,    /*! Send */
    EMMessageDirectionReceive,     /*! Receive */
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
 *  The sender
 */
@property (nonatomic, copy) NSString *from;

/*!
 *  The receiver
 */
@property (nonatomic, copy) NSString *to;

/*!
 *  Timestamp, the time of server received this message
 */
@property (nonatomic) long long timestamp;

/*!
 *  The time of client send/received this message
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
 *  Whether read ack has been sent or received, it indicates whether has received read ack for sender, and whether has send read ack for receiver
 */
@property (nonatomic) BOOL isReadAcked;

/*!
 *  Whether delivery ack has been sent or received, it indicates whether has received delivery ack for send, and whether has send delivery ack for receiver, SDK will automatically send delivery ack if EMOptions has set enableDeliveryAck
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
 *  Key type must be NSString, Value type must be NSString or NSNumber of BOOL, int, unsigned in, long long, double.
 */
@property (nonatomic, copy) NSDictionary *ext;

/*!
 *  Initialize message instance
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
