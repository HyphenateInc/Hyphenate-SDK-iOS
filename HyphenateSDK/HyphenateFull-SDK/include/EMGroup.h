/*!
 *  @header EMGroup.h
 *  @abstract Group
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMGroupOptions.h"

/*!
 *  Group
 */
@interface EMGroup : NSObject

/*!
 *  Group id
 */
@property (nonatomic, copy, readonly) NSString *groupId;

/*!
 *  Subject of the group
 */
@property (nonatomic, copy, readonly) NSString *subject;

/*!
 *  Description of the group
 */
@property (nonatomic, copy, readonly) NSString *description;

/*!
 *  The total number of group members
 */
@property (nonatomic, readonly) NSInteger occupantsCount __deprecated_msg("Use - membersCount");
@property (nonatomic, readonly) NSInteger membersCount;

/*!
 *  Setting options of group
 */
@property (nonatomic, strong, readonly) EMGroupOptions *setting;

/*!
 *  Owner of the group
 *
 *  Each group only has one owner
 */
@property (nonatomic, copy, readonly) NSString *owner;

/*!
 *  Member list of the group
 */
@property (nonatomic, copy, readonly) NSArray *members;

/*!
 *  Group‘s blacklist of blocked users
 *
 *  Need owner's authority to access, return nil if user is not the group owner.
 */
@property (nonatomic, strong, readonly) NSArray *bans __deprecated_msg("Use - blackList");
@property (nonatomic, strong, readonly) NSArray *blackList;

/*!
 *  All occupants of the group, includes the group owner and all other group members
 */
@property (nonatomic, strong, readonly) NSArray *occupants;

/*!
 *  Is Apple Push Notification Service enabled for group
 */
@property (nonatomic, readonly) BOOL isPushNotificationEnabled;

/*!
 *  Whether is a public group
 */
@property (nonatomic, readonly) BOOL isPublic;

/*!
 *  Whether block the current group‘s messages
 */
@property (nonatomic, readonly) BOOL isBlocked;

/*!
 *  Initialize a group instance
 *
 *  Please use [+groupWithId:]
 *
 *  @result nil
 */
- (instancetype)init __deprecated_msg("Use +groupWithId:");

/*!
 *  Get group instance, create a instance if it does not exist
 *
 *  @param aGroupId  Group id
 *
 *  @result Group instance
 */
+ (instancetype)groupWithId:(NSString *)aGroupId;

@end
