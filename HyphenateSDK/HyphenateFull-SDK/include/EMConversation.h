/*!
 *  @header EMConversation.h
 *  @abstract Chat conversation
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMMessageBody.h"

/*
 *  Conversation type
 */
typedef enum{
    EMConversationTypeChat  = 0,    /*! Chat */
    EMConversationTypeGroupChat,    /*! Group chat */
    EMConversationTypeChatRoom      /*! Chatroom chat */
} EMConversationType;

/*
 *  Message search direction
 */
typedef enum{
    EMMessageSearchDirectionUp  = 0,    /*! Search older messages */
    EMMessageSearchDirectionDownload    /*! Search newer messages */
} EMMessageSearchDirection;

@class EMMessage;

/*!
 *  Chat conversation
 */
@interface EMConversation : NSObject

/*!
 *  Unique identifier of conversation
 */
@property (nonatomic, copy, readonly) NSString *conversationId;

/*!
 *  Conversation type
 */
@property (nonatomic, assign, readonly) EMConversationType type;

/*!
 *  Count of unread messages
 */
@property (nonatomic, assign, readonly) int unreadMessagesCount;

/*!
 *  Conversation extend property
 */
@property (nonatomic, copy) NSDictionary *ext;

/*!
 *  Conversation latest message
 */
@property (nonatomic, strong, readonly) EMMessage *latestMessage;

/*!
 *  Insert a message to conversation, message's conversationId should equle to conversation's conversationId, message will be inserted to DB, and update conversation's property
 *
 *  @param aMessage  Message
 *
 *  @result Message insert result, YES: success, No: fail
 */
- (BOOL)insertMessage:(EMMessage *)aMessage;

/*!
 *  Delete a message
 *
 *  @param aMessageId  Message's ID who will be deleted
 *
 *  @result Message delete result, YES: success, No: fail
 */
- (BOOL)deleteMessageWithId:(NSString *)aMessageId;

/*!
 *  Delete all message of the conversation
 *
 *  @result Delete result, YES: success, No: fail
 */
- (BOOL)deleteAllMessages;

/*!
 *  Update a message, can't update message's messageId, conversation's latestMessage and so on properties will update after update the message
 *
 *  @param aMessage  Message
 *
 *  @result Message update result, YES: success, No: fail
 */
- (BOOL)updateMessage:(EMMessage *)aMessage;

/*!
 *  Mark a message as read
 *
 *  @param aMessageId  Message's ID who will be set read status
 *
 *  @result Result of mark message as read, YES: success, No: fail
 */
- (BOOL)markMessageAsReadWithId:(NSString *)aMessageId;

/*!
 *  Mark all message as read
 *
 *  @result Result of mark all message as read, YES: success, No: fail
 */
- (BOOL)markAllMessagesAsRead;

/*!
 *  Update conversation extend properties to DB
 *
 *  @result Extend properties update result, YES: success, No: fail
 */
- (BOOL)updateConversationExtToDB __deprecated_msg("setExt: will update extend properties to DB");

/*!
 *  Get a message with the ID
 *
 *  @param aMessageId  Message's id
 *
 *  @result Message instance
 */
- (EMMessage *)loadMessageWithId:(NSString *)aMessageId;

/*!
 *  Get more messages from DB, result messages are sorted by receive time, and NOT include the reference message, if reference messag's ID is nil, will fetch message from latest message
 *
 *  @param aMessageId  Reference message's ID
 *  @param aLimit      Count of messages to load
 *  @param aDirection  Message search direction
 *
 *  @result Message list<EMMessage>
 */
- (NSArray *)loadMoreMessagesFromId:(NSString *)aMessageId
                              limit:(int)aLimit
                          direction:(EMMessageSearchDirection)aDirection;

/*!
 *  Get more messages with specified type from DB, result messages are sorted by received time, if reference timestamp is negative, will fetch message from latest message, andd will fetch all messages that meet the condition if aLimit is negative
 *
 *  @param aType        Message type to load
 *  @param aTimestamp   Reference timestamp
 *  @param aLimit       Count of messages to load
 *  @param aSender      Message sender, will ignore it if it's empty
 *  @param aDirection   Message search direction
 *
 *  @result Message list<EMMessage>
 */
- (NSArray *)loadMoreMessagesWithType:(EMMessageBodyType)aType
                               before:(long long)aTimestamp
                                limit:(int)aLimit
                                 from:(NSString*)aSender
                            direction:(EMMessageSearchDirection)aDirection;

/*!
 *  Get more messages contain specified keywords from DB, result messages are sorted by received time, if reference timestamp is negative, will fetch message from latest message, andd will fetch all messages that meet the condition if aLimit is negative
 *
 *  @param aKeywords    Search content, will ignore it if it's empty
 *  @param aTimestamp   Reference timestamp
 *  @param aLimit       Count of messages to load
 *  @param aSender      Message sender, will ignore it if it's empty
*  @param aDirection    Message search direction
 *
 *  @result Message list<EMMessage>
 */
- (NSArray *)loadMoreMessagesContain:(NSString*)aKeywords
                               before:(long long)aTimestamp
                                limit:(int)aLimit
                                 from:(NSString*)aSender
                            direction:(EMMessageSearchDirection)aDirection;

/*!
 *  Load messages from DB in duration, result messages are sorted by receive time, user should limit the max count to load to avoid memory issue
 *
 *  @param aStartTimestamp  Start time's timestamp in miliseconds
 *  @param aEndTimestamp    End time's timestamp in miliseconds
 *  @param aMaxCount        Message search direction
 *
 *  @result Message list<EMMessage>
 */
- (NSArray *)loadMoreMessagesFrom:(long long)aStartTimestamp
                               to:(long long)aEndTimestamp
                         maxCount:(int)aMaxCount;

/*!
 *  Get latest message that received from others
 *
 *  @result Message instance
 */
- (EMMessage *)latestMessageFromOthers;


@end
