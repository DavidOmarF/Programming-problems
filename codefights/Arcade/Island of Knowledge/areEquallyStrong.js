function areEquallyStrong(yourLeft, yourRight, friendsLeft, friendsRight) {
    return Math.max(yourLeft, yourRight) == Math.max(friendsLeft, friendsRight) && yourLeft + yourRight == friendsLeft + friendsRight;
}
