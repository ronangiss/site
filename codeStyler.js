(function () {
  codeView()
}
)()

function codeView () {
  var pre = document.getElementsByTagName('pre')
  for (var i = 0; i < pre.length; i++) {
    pre[i].innerHTML = '<span class="line-number"></span>' + pre[i].innerHTML + '<span class="cl"></span>'
    var num = pre[i].innerHTML.split(/\n/).length
    for (var j = 0; j < num; j++) {
      var lineNum = pre[i].getElementsByTagName('span')[0]
      lineNum.innerHTML += '<span>' + (j + 1) + '</span>'
    }
  }
}