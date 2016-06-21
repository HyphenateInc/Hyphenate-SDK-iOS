/*!
 *  @header EMChatroomManagerDelegate.h
 *  @abstract This protocol defined the callbacks of chatroom
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

/*!
 *  The reason of be kicked out from chatroom
 */
typedef enum{
    EMChatroomBeKickedReasonBeRemoved = 0,  /*! Removed by owner  */
    EMChatroomBeKickedReasonDestroyed,      /*! Chatroom has been destroyed */
}EMChatroomBeKickedReason;

@class EMChatroom;

/*!
 *  Callbacks of chatroom
 */
@protocol EMChatroomManagerDelegate <NSObject>

@optional

/*!
 *  A user joined chatroom
 *
 *  @param aChatroom    Joined chatroom
 *  @param aUsername    The user who joined chatroom
 */
- (void)didReceiveUserJoinedChatroom:(EMChatroom *)aChatroom
                            username:(NSString *)aUsername;

/*!
 *  A user leaved chatroom
 *
 *  @param aChatroom    Leaved chatroom
 *  @param aUsername    The user who leaved chatroom
 */
- (void)didReceiveUserLeavedChatroom:(EMChatroom *)aChatroom
                            username:(NSString *)aUsername;

/*!
 *  User was kicked out from a chatroom
 *
 *  @param aChatroom    The chatroom which user was kicked out from
 *  @param aReason      The reason of user was kicked out
 */
- (void)didReceiveKickedFromChatroom:(EMChatroom *)aChatroom
                              reason:(EMChatroomBeKickedReason)aReason;


@end
