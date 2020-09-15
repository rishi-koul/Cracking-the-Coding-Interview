# Question says true length will be given, so please provide that

# Task: Replace any white spaces in middle to %20 and ignore whitespaces in the end

def URLify(url, true_len):
  # Removing ending white spaces
  url = url[:-(len(url) - true_len)]
  # replacing middle white spaces with "%20"
  new_url = url.replace(" ", "%20")
  return new_url

print(URLify("Mr John Smith   ", true_len = 13))
