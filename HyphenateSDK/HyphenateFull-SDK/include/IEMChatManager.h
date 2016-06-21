/*!
 *  @header IEMChatManager.h
 *  @abstract This protocol defined the operations of chat
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMChatManagerDelegate.h"
#import "EMConversation.h"

#import "EMMessage.h"
#import "EMTextMessageBody.h"
#import "EMLocationMessageBody.h"
#import "EMCmdMessageBody.h"
#import "EMFileMessageBody.h"
#import "EMImageMessageBody.h"
#import "EMVoiceMessageBody.h"
#import "EMVideoMessageBody.h"

@class EMError;

/*!
 *  Operations of chat
 */
@protocol IEMChatManager <NSObject>

@required

#pragma mark - Delegate

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 *  @param aQueue     The queue of call delegate method
 */
- (void)addDelegate:(id<EMChatManagerDelegate>)aDelegate
      delegateQueue:(dispatch_queue_t)aQueue;

/*!
 *  Remove delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)removeDelegate:(id<EMChatManagerDelegate>)aDelegate;

#pragma mark - Conversation

/*!
 *  Get all conversations, will load conversations from DB if not exist in memory
 *
 *  @result Conversation list<EMConversation>
 */
- (NSArray *)getAllConversations;

/*!
 *  Load all conversations from DB, will update conversation list in memory after this method is called
 *
 *  Synchronization method will block the current thread
 *
 *  @result Conversation list<EMConversation>
 */
- (NSArray *)loadAllConversationsFromDB;

/*!
 *  Get a conversation
 *
 *  @param aConversationId  Conversation id
 *  @param aType            Conversation type
 *  @param aIfCreate        Whether create conversation if not exist
 *
 *  @result Conversation
 */
- (EMConversation *)getConversation:(NSString *)aConversationId
                               type:(EMConversationType)aType
                   createIfNotExist:(BOOL)aIfCreate;

/*!
 *  Delete a conversation
 *
 *  @param aConversationId  Conversation id
 *  @param aDeleteMessage   Whether delete messages
 *
 *  @result Whether deleted successfully
 */
- (BOOL)deleteConversation:(NSString *)aConversationId
            deleteMessages:(BOOL)aDeleteMessage;

/*!
 *  Delete multiple conversations
 *
 *  @param aConversations  Conversation list<EMConversation>
 *  @param aDeleteMessage  Whether delete messages
 *
 *  @result Whether deleted successfully
 */
- (BOOL)deleteConversations:(NSArray *)aConversations
             deleteMessages:(BOOL)aDeleteMessage;

/*!
 *  Import multiple conversations to DB
 *
 *  @param aConversations  Conversation list<EMConversation>
 *
 *  @result Whether imported successfully
 */
- (BOOL)importConversations:(NSArray *)aConversations;

#pragma mark - Message

/*!
 *  Get message attachment path for the conversation, files in this path will also be deleted when delete the conversation
 *
 *  @param aConversationId  Conversation id
 *
 *  @result Attachment path
 */
- (NSString *)getMessageAttachmentPath:(NSString *)aConversationId;

/*!
 *  Import multiple messages
 *
 *  @param aMessages  Message list<EMMessage>
 *
 *  @result Whether imported successfully
 */
- (BOOL)importMessages:(NSArray *)aMessages;

/*!
 *  Update message to DB
 *
 *  @param aMessage  Message
 *
 *  @result Whether updated successfully
 */
- (BOOL)updateMessage:(EMMessage *)aMessage;

/*!
 *  Send read ack for message
 *
 *  Asynchronous methods
 *
 *  @param aMessage  Message instance
 */
- (void)asyncSendReadAckForMessage:(EMMessage *)aMessage;

/*!
 *  Send a message
 *
 *  Asynchronous methods
 *
 *  @param aMessage            Message instance
 *  @param aProgressCompletion The block of attachment upload progress
 *
 *  @param aCompletion         The block of send complete
 */
- (void)asyncSendMessage:(EMMessage *)aMessage
                progress:(void (^)(int progress))aProgressCompletion
              completion:(void (^)(EMMessage *message,
                                   EMError *error))aCompletion;

/*!
 *  Resend Message
 *
 *  Asynchronous methods
 *
 *  @param aMessage            Message instance
 *  @param aProgressCompletion The callback block of attachment upload progress
 *  @param aCompletion         The callback block of send complete
 */
- (void)asyncResendMessage:(EMMessage *)aMessage
                  progress:(void (^)(int progress))aProgressCompletion
                completion:(void (^)(EMMessage *message,
                                     EMError *error))aCompletion;

/*!
 *  Download message thumbnail attachments (thumbnails of image message or first frame of video image), SDK can download thumbail automatically, so user should NOT download thumbail manually except automatic download failed
 *
 *  Asynchronous methods
 *
 *  @param aMessage            Message instance
 *  @param aProgressCompletion The callback block of attachment download progress
 *  @param aCompletion         The callback block of download complete
 */
- (void)asyncDownloadMessageThumbnail:(EMMessage *)aMessage
                             progress:(void (^)(int progress))aProgressCompletion
                           completion:(void (^)(EMMessage * message,
                                                EMError *error))aCompletion;

/*!
 *  Download message attachment(voice, video, image or file), SDK can download voice automatically, so user should NOT download voice manually except automatic download failed
 *
 *  Asynchronous methods
 *
 *  @param aMessage            Message instance
 *  @param aProgressCompletion The callback block of attachment download progress
 *  @param aCompletion         The callback block of download complete
 */
- (void)asyncDownloadMessageAttachments:(EMMessage *)aMessage
                               progress:(void (^)(int progress))aProgressCompletion
                             completion:(void (^)(EMMessage *message,
                                                  EMError *error))aCompletion;


@end
