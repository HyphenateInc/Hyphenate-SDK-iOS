/*!
 *  @header EMChatManagerDelegate.h
 *  @abstract This protocol defined the callbacks of chat
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

@class EMMessage;
@class EMError;

/*!
 *  Chat related callbacks
 */
@protocol EMChatManagerDelegate <NSObject>

@optional

#pragma mark - Conversation

/*!
 *  The conversation list has changed
 *
 *  @param aConversationList  Conversation list<EMConversation>
 */
- (void)didUpdateConversationList:(NSArray *)aConversationList;

#pragma mark - Message

/*!
 *  Received messages
 *
 *  @param aMessages  Message list<EMMessage>
 */
- (void)didReceiveMessages:(NSArray *)aMessages;

/*!
 *  Received cmd messages
 *
 *  @param aCmdMessages  Cmd message list<EMMessage>
 */
- (void)didReceiveCmdMessages:(NSArray *)aCmdMessages;

/*!
 *  Received read acks
 *
 *  @param aMessages  Read acked message list<EMMessage>
 */
- (void)didReceiveHasReadAcks:(NSArray *)aMessages;

/*!
 *  Received deliver acks
 *
 *  @param aMessages  Deliver acked message list<EMMessage>
 */
- (void)didReceiveHasDeliveredAcks:(NSArray *)aMessages;

/*!
 *  Message status has changed
 *
 *  @param aMessage  Message whose status changed
 *  @param aError    Error info
 */
- (void)didMessageStatusChanged:(EMMessage *)aMessage
                          error:(EMError *)aError;

/*!
 *  Attachment status has changed
 *
 *  @param aMessage  Message whose attachment status changed
 *  @param aError    Error
 */
- (void)didMessageAttachmentsStatusChanged:(EMMessage *)aMessage
                                     error:(EMError *)aError;

@end
