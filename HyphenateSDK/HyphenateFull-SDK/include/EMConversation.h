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
    EMConversationTypeChat  = 0,    /*!  one to one chat room type */
    EMConversationTypeGroupChat,    /*!  Group chat room type */
    EMConversationTypeChatRoom      /*!  Chatroom chat room type */
} EMConversationType;

/*
 *  Message search direction
 */
typedef enum{
    EMMessageSearchDirectionUp  = 0,    /*!  Search older messages */
    EMMessageSearchDirectionDown        /*!  Search newer messages */
} EMMessageSearchDirection;

@class EMMessage;
@class EMError;

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
 *  Conversation extension property
 */
@property (nonatomic, copy) NSDictionary *ext;

/*!
 *  Conversation latest message
 */
@property (nonatomic, strong, readonly) EMMessage *latestMessage;

/*!
 *  Insert a message to a conversation. ConversationId of the message should be the same as conversationId of the conversation in order to insert the message into the conversation correctly.
 *
 *  @param aMessage Message
 *  @param pError   Error
 */
- (void)insertMessage:(EMMessage *)aMessage
                error:(EMError **)pError;

/*!
 *  Insert a message to the end of a conversation. ConversationId of the message should be the same as conversationId of the conversation in order to insert the message into the conversation correctly.
 *
 *  @param aMessage Message
 *  @param pError   Error
 *
 */
- (void)appendMessage:(EMMessage *)aMessage
                error:(EMError **)pError;

/*!
 *  Delete a message
 *
 *  @param aMessageId   MessageId of the message to be deleted
 *  @param pError       Error
 *
 */
- (void)deleteMessageWithId:(NSString *)aMessageId
                      error:(EMError **)pError;

/*!
 *  Delete all message of a conversation
 *  @param pError       Error
 */
- (void)deleteAllMessages:(EMError **)pError;

/*!
 *  Update a local message, conversation's latestMessage and other properties will be updated accordingly. Please note that messageId can not be updated.
 *
 *  @param aMessage Message
 *  @param pError   Error
 *
 */
- (void)updateMessageChange:(EMMessage *)aMessage
                      error:(EMError **)pError;

/*!
 *  Mark a message as read
 *
 *  @param aMessageId   MessageID
 *  @param pError       Error
 *
 */
- (void)markMessageAsReadWithId:(NSString *)aMessageId
                          error:(EMError **)pError;

/*!
 *  Mark all message as read
 *
 *  @param pError   Error
 *
 */
- (void)markAllMessagesAsRead:(EMError **)pError;

/*!
 *  Get a message with the ID
 *
 *  @param aMessageId       MessageID
 *  @param pError           Error
 *
 */
- (EMMessage *)loadMessageWithId:(NSString *)aMessageId
                           error:(EMError **)pError;

/*!
 *  Get last received message
 *
 *  @result Message instance
 */
- (EMMessage *)lastReceivedMessage;

#pragma mark - Async method

/*!
 *  Load messages from a specified message, returning messages are sorted by receiving timestamp. If the aMessageId is nil, return the latest received messages.
 *
 *  @param aMessageId       Reference message's ID
 *  @param aCount           Count of messages to load
 *  @param aDirection       Message search direction
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)loadMessagesStartFromId:(NSString *)aMessageId
                          count:(int)aCount
                searchDirection:(EMMessageSearchDirection)aDirection
                     completion:(void (^)(NSArray *aMessages, EMError *aError))aCompletionBlock;

/*!
 *  Load messages with specified type, returning messages are sorted by receiving timestamp. If reference timestamp is negative, load from the latest messages; if message count is negative, load all messages that meet the condition.
 *
 *  @param aType            Message type to load
 *  @param aTimestamp       Reference timestamp
 *  @param aLimit           Count of messages to load
 *  @param aUsername        Message sender (optional)
 *  @param aDirection       Message search direction
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)loadMessagesWithType:(EMMessageBodyType)aType
                   timestamp:(long long)aTimestamp
                       count:(int)aCount
                    fromUser:(NSString*)aUsername
             searchDirection:(EMMessageSearchDirection)aDirection
                  completion:(void (^)(NSArray *aMessages, EMError *aError))aCompletionBlock;

/*!
 *  Load messages with specified keyword, returning messages are sorted by receiving timestamp. If reference timestamp is negative, load from the latest messages; if message count is negative, load all messages that meet the condition.
 *
 *  @param aKeywords        Search content, will ignore it if it's empty
 *  @param aTimestamp       Reference timestamp
 *  @param aCount           Count of messages to load
 *  @param aSender          Message sender (optional)
 *  @param aDirection       Message search direction
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)loadMessagesWithKeyword:(NSString*)aKeyword
                      timestamp:(long long)aTimestamp
                          count:(int)aCount
                       fromUser:(NSString*)aSender
                searchDirection:(EMMessageSearchDirection)aDirection
                     completion:(void (^)(NSArray *aMessages, EMError *aError))aCompletionBlock;

/*!
 *  Load messages within specified time range, retruning messages are sorted by receiving timestamp
 *
 *  @param aStartTimestamp  Start time's timestamp in miliseconds
 *  @param aEndTimestamp    End time's timestamp in miliseconds
 *  @param aCount           Message search direction
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)loadMessagesFrom:(long long)aStartTimestamp
                      to:(long long)aEndTimestamp
                   count:(int)aCount
              completion:(void (^)(NSArray *aMessages, EMError *aError))aCompletionBlock;

@end
