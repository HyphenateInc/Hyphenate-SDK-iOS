/*!
 *  @header EMChatroomManagerDelegate.h
 *  @abstract This protocol defined the callbacks of chatroom
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

/*!
 *  The casuse for kicking a user out of a chatroom
 */
typedef enum{
    EMChatroomBeKickedReasonBeRemoved = 0,  /*!  Removed by chatroom owner  */
    EMChatroomBeKickedReasonDestroyed,      /*!  Chatroom has been destroyed */
}EMChatroomBeKickedReason;

@class EMChatroom;

/*!
 *  Callbacks of chatroom
 */
@protocol EMChatroomManagerDelegate <NSObject>

@optional

/*!
 *  Delegate method will be invoked when a user joins a chatroom.
 *
 *  @param aChatroom    Joined chatroom
 *  @param aUsername    The user who joined chatroom
 */
- (void)userDidJoinChatroom:(EMChatroom *)aChatroom
                       user:(NSString *)aUsername;

/*!
 *  Delegate method will be invoked when a user leaves a chatroom.
 *
 *  @param aChatroom    Left chatroom
 *  @param aUsername    The user who leaved chatroom
 */
- (void)userDidLeaveChatroom:(EMChatroom *)aChatroom
                        user:(NSString *)aUsername;

/*!
 *  Delegate method will be invoked when a user is dismissed from a chat room
 *
 *  @param aChatroom    aChatroom
 *  @param aReason      The reason of dismissing user from the chat room
 */
- (void)didDismissFromChatroom:(EMChatroom *)aChatroom
                        reason:(EMChatroomBeKickedReason)aReason;
@end
