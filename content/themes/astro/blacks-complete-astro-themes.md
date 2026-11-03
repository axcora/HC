---
layout: themes-detil.cax
title: Blacks - Astro Multipurpose Template - Portfolio, Gallery, Blog, Landing
description: Astro multipurpose dark template with portfolio, image gallery, video gallery, blog, landing, SEO auto. Modern, fast, responsive, own 100% source, one-time.
is_premium: true
price: $65
image: astro/astro-complete-template-themes_yoyqsn.jpg
features:
  - Astro + Preact
  - Multipurpose Dark Theme
  - Portfolio + Gallery + Video
  - Blog + Categories + Tags
  - Pagination + Article Page
  - Contact Form
  - SEO Auto + Picture + Transition
  - Own 100% Source
download: https://creativitaz.gumroad.com/l/astrojs-blacks
demo: https://astro-blacks-themes.pages.dev/
tags:
    - astro
    - multipurpose template
    - portfolio template
    - dark template
    - gallery template
    - blog template
    - astro template
    - blacks template
    - premiumthemes
    - featured
    - featuredpremium
faq:
  - q: "What is Blacks, and what problem does it solve?"
    a: "Blacks is a premium Astro multipurpose dark template built with Astro and Preact. It ships with a portfolio, image gallery, video gallery, blog with categories and tags, pagination, services, promotion widgets, a contact form, SEO auto, Picture optimization, and page transitions. Site configuration lives in src/data/config.json, homepage content in src/data/home.json, and each page type lives as Markdown files in src/pages/. Instead of assembling a multipurpose dark site from scratch, you install the project, edit JSON and Markdown, and the site is live."
  - q: "Do I need to know Astro or Preact to use Blacks?"
    a: "You need Node.js and a terminal to install and run the project, but daily content editing happens through JSON and Markdown. Site-wide settings live in src/data/config.json, the homepage in src/data/home.json, and each page in src/pages/ (about, blog, contact, gallery, services, content). If you can edit JSON and Markdown, you can customize most of it. Astro and Preact knowledge helps for layout changes."
  - q: "How do I install and run Blacks locally?"
    a: "Install Node.js from nodejs.org. Download the source code and extract it into your project folder. Open a terminal, run cd C:\Users\pcname\desktop\project (replace pcname and project with your own), then npm install and npm run dev. Open localhost:4321 in your browser."
  - q: "How do I configure the site title, navigation, social, and contact?"
    a: "Open src/data/config.json. Change url, title, description, favicon, and image. The navbar field is the navbar title, and the nav_list array holds each menu with nav and link. The social array holds each social entry with title and link. The contact block holds address, city, country, phone, and email. Save the file and the site updates. For the homepage, open src/data/home.json and edit with the same approach."
  - q: "How do I add a blog post or a gallery item?"
    a: "For a blog post, create a .md file in src/pages/blog/ (for example hello-world.md) with frontmatter: layout ../../design/blog/blogpost.astro, title, description, image, pubDate, tags, and categories. For an image gallery item, create a .md file in src/pages/gallery/image/ with layout ../../../design/gallery/imagepost.astro and the same frontmatter fields. For a video gallery item, create a .md file in src/pages/gallery/video/ with layout ../../../design/gallery/videopost.astro and add a video field containing only the YouTube video ID (for example B6RpLTSCz5o, not the full URL)."
  - q: "What files should I never delete or rename?"
    a: "Do not delete or rename the [...page].astro files. They power pagination and dynamic routing for the blog, image gallery, video gallery, and services sections. If you delete them, the listing pages break. You also need to keep the four promotion widgets in src/pages/content/ — the theme expects four, and missing entries leave empty slots on article pages."
  - q: "How do I update about, contact, services, and gallery index pages?"
    a: "For about, edit src/pages/about/index.md with layout ../../design/about.astro and the frontmatter title, description, image, and intro. For contact, edit src/pages/contact/index.md with layout ../../design/contact.astro. For the gallery index, edit src/pages/gallery/index.md with layout ../../design/gallery/start.astro and the fields image_icon, image_text, video_icon, and video_text. For services, create or edit .md files in src/pages/services/ with layout ../../design/services/servicespost.astro."
  - q: "What are the promotion widgets, and how do I use them?"
    a: "The promotion widgets display services or blog promotions inside article pages. Create four .md files in src/pages/content/, each with layout ../../design/servicespost.astro and the frontmatter title, link, description, image, and pubDate. The theme expects four, so create all four even if you leave some content minimal. Edit them when you want to promote a new service, blog post, or offer."
  - q: "Is SEO handled automatically?"
    a: "Yes. Blacks ships with auto SEO injection and Astro Picture optimization, with meta title, description, and image pulled from src/data/config.json and per-page frontmatter. The blog supports categories, tags, and pagination, which gives search engines clean indexable listing pages. The Astro static output plus page transitions keeps the site fast and search-ready."
  - q: "How do I deploy Blacks, and what is the license?"
    a: "Open astro.config.mjs and set site to your domain, keeping the preact() integration. Push the project to GitHub or GitLab, then register on Netlify, Vercel, or Cloudflare with your Git account, create a new project, connect your repository, select Astro as the framework, and click deploy. The license is a one-time purchase at 65 dollars, and you own 100 percent of the source. You can use it on personal and client projects. The license does not permit reselling or redistributing the template itself. Live demo astro-blacks-themes.pages.dev. Download creativitaz.gumroad.com/l/astrojs-blacks. For support, email creativebydre@gmail.com, and custom headless CMS integration is available through the Fiverr link in the article."
---

### Blacks Astro JS Photography ART Themes

When it comes to creating a multipurpose project, leveraging the power of Astro.js can truly elevate your site’s performance and SEO. Imagine a framework that allows you to build fast, optimized websites with minimal effort. [Astro.js](https://astro.build) is designed for speed, enabling you to deliver content quickly by rendering only what’s necessary. This means your users get a seamless experience, and search engines can easily crawl your site, boosting your rankings.

https://www.youtube.com/watch?v=YwnAax4okAg

Incorporating art themes into your project not only enhances visual appeal but also engages your audience on a deeper level. By using components and layouts that reflect artistic styles, you can create a unique brand identity. Plus, with Astro's support for various front-end frameworks, you can mix and match to find the perfect aesthetic for your project.

Don’t forget about the importance of accessibility and responsive design. [Astro.js](https://astro.build) makes it easy to ensure that your site looks great on any device, which is crucial for keeping users engaged. By focusing on these elements, you’re not just building a website; you’re crafting an experience that resonates with visitors and keeps them coming back.

---------------------------

### [Astro themes](https://astro.build) project installation 

How to install astro js themes

### Local Installation

+ For first you need to install node js , you can [download node here](https://nodejs.org/en/download/)
+ Download source code project and extract on your project folder.
+ Access your project folder with terminal , for example your project folder is locate on desktop so you can run this command `cd C:\Users\pcname\desktop\project` - change pcname with your pc name and change project with your project name.
+ After that you can run installation command `npm install`
+ Now you can run your project on your local devices , with run this command `npm run dev`
+ Visit `localhost:4321`

---------------------------

### Work with this astro blacks

Now you need to update and config your website,for first you need to access on `src/data` open `config.json` and `home.json` files and change with your needed.

You can change title, description ,and others for your website.

---------------------------

#### Configuration and update home page

access on `src/data` and open `config.json` files and change with your needed.

You can change title, description ,and others for your website.

fontformatter

```js
{
    "url": "insert your website url domain here",
    "title": "insert title in here",
    "description": "Your website description", 
    "favicon": "url image for your favicon",
    "image": "url image for image banner",


    "navbar": "Navbar title in here",
    "nav_list": [
      {
        "nav": "Home",
        "link": "/"
      },
// if you want add new nav menu you can simple, just copy and paste code like this..
      {
        "nav": "This is nav name",
        "link": "url for your nav menu in here"
      },

// implementation navigation area
    "nav_list": [
      {
        "nav": "Home",
        "link": "/"
      },  
      {
        "nav": "This is nav name",
        "link": "url for your nav menu in here"
      }
    ],


// social media area
    "social": [
      {
        "title": "Facebook",
        "link": "https://www.fiverr.com/creativitas/"
      },
      {
        "title": "This is your social media name",
        "link": "social media url in here..."
      },
      {

        "title": "Instagram",
        "link": "https://www.fiverr.com/creativitas/create-your-custom-website-and-app"
      }
    ],


// your contact area
    "contact": 
      {
        "address": "insert your address in here",
        "city": "insert city here..",
        "country": "Insert country in here...",
        "phone": "insert your phone number here..",
        "email": "insert you email here...."
      } 
}
```

After you have setup your config files, you can save it , for update your website.

Next you can move to `src/data/home.json` the concept is same like `config.json` just change and update with your needed, this `home.json` for update your homepage area.

---------------------------

#### Update About Page

Acces on `src/pages/about/index.md`

`about` for change your about page article, you can open `index.md` files and change with your needed.

Fontformatter :

```js
---
layout: ../../design/about.astro # default template
title: your title in here
description: Input description in here
image: insert url image here
intro: your intro in here
---

Write article with markdown lang in here...

```

Update and change with you needed, then save it.

---------------------------

#### Update Article Blog Page

Access on `src/pages/blog`

`blog` this area for write blog post artilce, note: don't delete or change `[..pages].astro` file you can create new article by create new .md files and name it with your article for example `hello-wolrd.md` , then  you can insert this fontformatter.

```js
---
layout: ../../design/blog/blogpost.astro # this is default themes
title: "write your title in here"
description: "insert description here"
image: insert your image url
pubDate: insert date example 2023-12-04
tags: ["insert tag here", "tag1", "tag2"]
categories: 'insert categories in here'
---

Write your content with markdown lang here...

```

after you have update, save it.

For simple step, you can copy and paste from example.md files, then update / edit with you needed.

---------------------------

#### Update Contact Page

Access on `src/pages/contact/index.md`

`contact` this area for update your contact artilce page

Fontformatter

```yml
---
layout: ../../design/contact.astro # default themes
title: title for contact page here...
description: Your description in here
image: insert url image here..
---
write your contact content here...
```

after you have update, save it.

---------------------------

#### Update Gallery Index

Access on `src/pages/gallery/index.md`

`gallery` this area for update your gallery index page

Fontformatter

```yml
---
layout: ../../design/gallery/start.astro # default themes
title: Title for your gallery page here...
description: INsert description gallery page here...
image: Insert url for image cover here...
image_icon: insert url for image gallery here...
image_text: Insert text info for your image gallery here..
video_icon: insert your video gallery icon here...
video_text: insert your text info for video gallery here...
---
```

after you have update, save it.

Next you can create image or video gallery content.

---------------------------

#### Update Image Gallery

Access on `src/pages/gallery/image`

`gallery/image` this area for update your gallery image page

Note: don't delete `[...page].astro` files.

Fontformatter

```yml
---
layout: ../../../design/gallery/imagepost.astro # default themes
title: Insert title in here..
description: Description in here..
image: insert url image here...
pubDate: insert publish date here.. # example : 2023-12-05
tags: ["insert tag here,," , "tag1" , "tag2"]
categories: 'insert categories here..'
---
Write content in here...

```

after you have update, save it.

For simple and fast step, you can copy and paste from example .md files then edit with your needed.

---------------------------

#### Update Video Gallery

Access on `src/pages/gallery/video`

`gallery/video` this area for update your gallery video page

Note: don't delete `[...page].astro` files.

Fontformatter

```yml
---
layout: ../../../design/gallery/videopost.astro # default themes
title: Insert title in here..
description: Description in here..
image: insert url image here...
video: Copy the back of the video URL from YouTube , example B6RpLTSCz5o - or you can check on example md files
pubDate: insert publish date here.. # example : 2023-12-05
tags: ["insert tag here,," , "tag1" , "tag2"]
categories: 'insert categories here..'
---
Write content in here...

```

after you have update, save it.

For simple and fast step, you can copy and paste from example .md files then edit with your needed.

---------------------------

#### Update Services Page

Access on `src/pages/services`

`services` this area for update your services artilce page

Note: don't delete `[...page].astro` files.

Fontformatter

```yml
---
layout: ../../design/services/servicespost.astro # default themes
title: insert title in here...
pubDate: insert publish date here.. # example : 2023-12-05
intro: insert intro your services here....
description: insert description here...
image: inser url image here...
tags: ["insert tag here," , "tag1" , "tag2"]
---

write content in here....

```

after you have update, save it.

For simple and fast step, you can copy and paste from example .md files then edit with your needed.

---------------------------

#### Update Promotion WIdget / Content

Acces on `src/pages/content`

`content` for displaying promotion services or blog on your post article .

Note: you need to create four promotion widget

Fontformatter :

```yml
---
layout: ../../design/servicespost.astro # default
title: insert title in here...
link: link for widget promotion...
description: insert description here...
image: insert url image here...
pubDate: 2023-11-28
---


```

Update and change with you needed, then save it.

---------------------------

### Cloud Installation

Before push your project, you need to add your domain.
For first you can open `astro.config.mjs`

and change site url with your domain name , example

```js
export default defineConfig({
  site: 'yourdomain.com',
  integrations: [preact()]
});
```

change `yourdomain.com` with your domain name.

+ After you have finish your project, now you can make your site live. so you need push your project in to git.
+ Register and create an account on [github](https://github.com) / gitlab
+ After you have create github account
+ Create new repo and name it with your project
+ Next open your project folder with terminal, and copy paste from github command from your repo - for push your project in to your github repo.
+ Now you need to register or create an account on modern static hosts such as vercel, netlify, [cloudflare](https://cloudflare.com) and others . Register with your git account.
+ Next you can create new project or page - then select or integration with your github repo project.
+ Click deploy - and select astro as framework
+ Finish !! your website is live !!

If you want , you can use our services for work with headless cms and setup your website project,until your website is live !!
