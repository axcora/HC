---
layout: themes-detil.cax
title: Jekyll Redirect Link Source Code Free
description: Learn how to implement jekyll project for redirect link URL.
image: logo/jekyllls_aukic9.jpg
features:
 - JAMSTACK
 - Ruby
 - Jekyll
 - Redirect Link
 - Easy Installation
 - Learn Project
 - Modern static host support for like netlify vercel cloudflare pages and others.
 - Documentation Ready
 - Full Source Code Themes Template Project
download: https://creativitaz.gumroad.com/l/jekyll-redirect-link
demo: 
tags:
  - themestemplate
  - website themes
  - website template
  - blog themes
  - blog template
  - how to
  - learn
  - redirect link
  - themes
  - template
  - blog
  - jekyll
  - jekyllthemes
  - jamstackthemes
  - freethemes
---
Jekyll redirect link source code , implementation how to use redirect link with jekyll project.

### Installation

+ For first make sure you have install bundler, ruby and jekyll on your devices. or read documentation how to install jekyll on your devices - https://jekyllrb.com/docs/installation/
+ Download this source code file project.
+ Open terminal and run bundle install , then run bundle exec jekyll serve or jekyll serve - open web browser and visit localhost:4000

### Implement with existing jekyll project

Open your jekyll project and run
`gem install jekyll-redirect-from`

or open Gemfile with code editor, then input this code :
```
group :jekyll_plugins do
  gem 'jekyll-redirect-from'
end
```

Now open _config.yml and insert plugins
```
plugins:
  - jekyll-redirect-from

whitelist:
  - jekyll-redirect-from

redirect_from:
  json: false
```

### How to implementation jekyll redirect form plugins.


#### Redirect Internal Link
redirect url to internal link ,if you want redirect from your page or post to internal url ,example about page and others.

Please add the array to the YAML front-matter of your page or post
```
title: Redirect Internal Link
description: description Redirect internal Link
redirect_to:
  - /how
```


#### Redirect Out Link External
redirect url out to external link , if you want redirect from your page or post to external url.

Please add the array to the YAML front-matter of your page or post
```
title: Redirect out Link
description: description Redirect out Link
redirect_to:
  - https://www.youtube.com/watch?v=7E-uPPqSrVg
```


#### Redirect standard link
redirect standard from other url or old url to your page or post.

Please add the array to the YAML front-matter of your page or post
```
title: Redirect standard
description: Description in here
redirect_from:
  - /id/123
  - /2023/06/27/link-form.html
```

#### Redirect with permalink
redirect use permalink method , if you want redirect from your old url post or page to new permalink.

Please add the array to the YAML front-matter of your page or post
```
title: Redirect with permalink
description: Description in here
redirect_from:
  - /id/234
  - /link-from-permalink.html
permalink: /id/234
```


#### Short URL
How to create short url jekyll website and blog

If you want to change your url for page and post, you can use permalink.

Please add the array to the YAML front-matter of your page or post
```
permalink: /ty11
```


Finish, We hope you can learn and implement about jekyll redirect link.
