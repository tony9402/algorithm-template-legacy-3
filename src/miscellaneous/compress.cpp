//title: Value Compress
//prefix: compress
//description: Value Compress
sort($TM_SELECTED_TEXT.begin(), $TM_SELECTED_TEXT.end());
$TM_SELECTED_TEXT.erase(unique($TM_SELECTED_TEXT.begin(),$TM_SELECTED_TEXT.end()), $TM_SELECTED_TEXT.end());