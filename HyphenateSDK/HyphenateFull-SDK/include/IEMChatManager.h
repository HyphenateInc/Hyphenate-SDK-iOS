/*!
 *  @header IEMChatManager.h
 *  @abstract This protocol defines the operations of chat
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
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)addDelegate:(id<EMChatManagerDelegate>)aDelegate;

/*!
 *  Remove delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)removeDelegate:(id<EMChatManagerDelegate>)aDelegate;

#pragma mark - Conversation

/*!
 *  Get all conversations, by loading conversations from DB if not exist in memory
 *
 *  @result Conversation list<EMConversation>
 */
- (NSArray *)getAllConversations;

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
 *  @param aConversationId      Conversation id
 *  @param isDeleteMessages     Whether delete messages
 *  @param aCompletionBlock     The callback block of completion
 *
 */
- (void)deleteConversation:(NSString *)aConversationId
          isDeleteMessages:(BOOL)aIsDeleteMessages
                completion:(void (^)(NSString *aConversationId, EMError *aError))aCompletionBlock;

/*!
 *  Delete multiple conversations
 *
 *  @param aConversations       Conversation list<EMConversation>
 *  @param aIsDeleteMessages    Whether delete messages
 *  @param aCompletionBlock     The callback block of completion
 *
 */
- (void)deleteConversations:(NSArray *)aConversations
           isDeleteMessages:(BOOL)aIsDeleteMessages
                 completion:(void (^)(EMError *aError))aCompletionBlock;

/*!
 *  Import multiple conversations to DB
 *
 *  @param aConversations   Conversation list<EMConversation>
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)importConversations:(NSArray *)aConversations
                 completion:(void (^)(EMError *aError))aCompletionBlock;

#pragma mark - Message

/*!
 *  Get message attachment local path for the conversation. Delete the conversation will also delete the files under the file path.
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
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)importMessages:(NSArray *)aMessages
            completion:(void (^)(EMError *aError))aCompletionBlock;

/*!
 *  Update message
 *
 *  @param aMessage  Message
 *  @param aSuccessBlock    The callback block of completion
 *
 */
- (void)updateMessage:(EMMessage *)aMessage
           completion:(void (^)(EMMessage *aMessage, EMError *aError))aCompletionBlock;

/*!
 *  Send read acknowledgement for message
 *
 *
 *  @param aMessage  Message instance
 *  @param aCompletionBlock    The callback block of completion
 *
 */
- (void)sendMessageReadAck:(EMMessage *)aMessage
                     completion:(void (^)(EMMessage *aMessage, EMError *aError))aCompletionBlock;

/*!
 *  Send a message
 *
 *
 *  @param aMessage            Message instance
 *  @param aProgressBlock      The block of attachment upload progress
 *  @param aCompletion         The block of send complete
 */
- (void)sendMessage:(EMMessage *)aMessage
           progress:(void (^)(int progress))aProgressBlock
         completion:(void (^)(EMMessage *message, EMError *error))aCompletionBlock;

/*!
 *  Resend Message
 *
 *  @param aMessage         Message instance
 *  @param aProgressBlock   The callback block of attachment upload progress
 *  @param aCompletion      The callback block of send complete
 */
- (void)resendMessage:(EMMessage *)aMessage
                  progress:(void (^)(int progress))aProgressBlock
                completion:(void (^)(EMMessage *message, EMError *error))aCompletionBlock;

/*!
 *  Download message thumbnail (thumbnail of image message or first frame of video image), SDK downloads thumbails automatically, no need to download thumbail manually unless automatic download failed.
 *
 *  @param aMessage            Message instance
 *  @param aProgressBlock      The callback block of attachment download progress
 *  @param aCompletion         The callback block of download complete
 */
- (void)downloadMessageThumbnail:(EMMessage *)aMessage
                        progress:(void (^)(int progress))aProgressBlock
                      completion:(void (^)(EMMessage *message, EMError *error))aCompletionBlock;

/*!
 *  Download message attachment(voice, video, image or file), SDK downloads attachment automatically, no need to download attachment manually unless automatic download failed
 *
 *
 *  @param aMessage            Message instance
 *  @param aProgressBlock      The callback block of attachment download progress
 *  @param aCompletion         The callback block of download complete
 */
- (void)downloadMessageAttachment:(EMMessage *)aMessage
                         progress:(void (^)(int progress))aProgressBlock
                       completion:(void (^)(EMMessage *message, EMError *error))aCompletionBlock;
@end
