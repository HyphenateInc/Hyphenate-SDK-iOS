/*!
 *  @header EMGroupOptions.h
 *  @abstract Group property options
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#define KSDK_GROUP_MINUSERSCOUNT 3
#define KSDK_GROUP_USERSCOUNTDEFAULT 200

/*!
 *  Group style
 */
typedef enum{
    EMGroupStylePrivateOnlyOwnerInvite  = 0,    /*!  Private groups, only owner can invite users to join */
    EMGroupStylePrivateMemberCanInvite,         /*!  Private groups, both owner and members can invite users to join  */
    EMGroupStylePublicJoinNeedApproval,         /*!  Public groups, owner can invite users to join; User can join group after owner approves user's group request */
    EMGroupStylePublicOpenJoin,                 /*!  Public groups, user can join the group freely */
}EMGroupStyle;

/*!
 *  Group options
 */
@interface EMGroupOptions : NSObject

/*!
 *  Group style
 */
@property (nonatomic) EMGroupStyle style;

/*!
 *  The group capacity (3-2000, the default is 200)
 */
@property (nonatomic) NSInteger maxUsersCount;

@end
