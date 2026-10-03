---
layout: themes-detil.cax
title: Docus - Astro Starlight Docs Template - Documentation, Blog, Landing
description: Astro Starlight docs template with documentation, blog, landing page, search, sidebar, dark mode. MDX ready, SEO auto, fast, own 100% source, one-time.
image: astro/astrodocumentationwebsite_ltdbcx.jpg
features:
  - Astro + Starlight
  - Documentation + Blog + Landing
  - Sidebar Nav + Search
  - Dark Mode + SEO Auto
  - MDX + Markdown
  - Categories + Tags + Pagination
  - Contact Form
  - Own 100% Source
download: https://creativitaz.gumroad.com/l/starlightastrodocus
demo: https://astrodoc.pages.dev/
tags:
    - astro
    - starlight
    - documentation template
    - docs template
    - blog template
    - astro template
    - documentation website
    - landing page
    - astro docs
    - premiumthemes
    - jamstackthemes
---
## Docus Astro Starlight project.

A project present by [creativitas](https://www.fiverr.com/creativitas)

Hire developer : [https://www.fiverr.com/users/creativitas](https://www.fiverr.com/users/creativitas)

![docus astro js](astrodocumentationwebsite.jpg)

-----

### How to

### Installation

+ For first you can download astro docus project source code files. [Download Now  →](https://creativitaz.gumroad.com/l/starlightastrodocus)
+ Next you can download node js and install on your local devices. [Download Node  →](https://nodejs.org/en/download/)
+ Create a new project folder name it with astrodocu on your desktop or where you installed node js.
+ Extract source code files and copy all files in to your project folder , for example you have create astrodocu on your desktop.
+ Ok, after you have create new project folder  next we need to can acces your project using terminal, so run this command C:\Users\pcname\Desktop\astrodocu change pcname with your pc name and change astrodocu with your project name.
+ Now we need to install source code project with terminal, run this command npm install
+ After you have install it , next we can test run this project `run npm run dev`
+ Open `localhost:4321`

-----

### Astro Docus Folder Structure

You need to know about the folder structure to make it easier for you to customize your documentation site.

![astro docu starlight](https://wsrv.nl/?url=https://public-files.gumroad.com/2wwhmhuajk66om3t3o5d70oyq12e&w=1000&output=webp)

Astro Docus folder structure - we work on src folder.

public - this folder for your storage files example like image , icon and others.

src
+ assets for your documentation files, but we recommend you, to save your files into files in public/src/assets/
+ content - This area is for your documentation content within the doc folder
+ data - All your data files here, such as home pages, static pages, and configuration design UI.
+ design - For the layout theme of your website project.
+ pages - For static page and your blog content article
+ styles - Custom CSS for your astro starlight documentation project.
+ widget - This folder for widget design area, like navbar and others.

astro.config.mjs - For configuration your website, on this files you can customises the sidebar documentation menu navigation.

----

### Configuration Astro Docus

You can configure your documentation site with the update configuration menu.

Open astro.config.mjs files with code editor, then update with your needed ,You can change the configuration and adapt it to the documentation articles you have created, if you have completed your project.

`astro.config.mjs `
```
export default defineConfig({
site: 'your website url in here',
integrations: [
starlight({
title: 'Your website title',
logo: {src: 'Image logo URL in here..',},
customCss: ['Your custom css in here..',],
social: { github: 'Your github repo here..', },
sidebar: [

{label: 'Title for your categories documentation article..',
items: [
{ label: 'Your doc article 1', link: 'Link url article 1 in here..' },
{ label: 'Your doc article 2 ', link: 'Link url article 2 in here..' },
],
},

{label: 'New categories title for documentation article..',
items: [
{ label: 'Your new doc here..', link: 'Link url in here...' },
{ label: 'New doc 2 grouping in here...',
items: [
{ label: 'New doc 2 title article 1', link: 'Link URL for new doc 1 ' },
{ label: 'New doc 2 title article 1', link: 'Link URL for new doc 2 ' },
],
},
],
});
```

Implementation
```
export default defineConfig({
site: 'https://astrodoc.pages.dev',
integrations: [
starlight({
title: 'Blacks',
logo: {src: './src/assets/astrologos.png',},
customCss: ['./src/styles/base.css',],
social: { github: 'https://github.com/mesinkasir', },
sidebar: [

{label: 'Get Start',
items: [
{ label: 'Start', link: '/getstart/' },
{ label: 'Installation', link: '/getstart/installation' },
{ label: 'Download', link: '/getstart/download' },
],
},

{label: 'Folder Structure',
items: [
{ label: 'Index', link: '/folder/' },
{ label: 'Content',
items: [
{ label: 'Services Folder', link: '/folder/content/services' },
{ label: 'Services file', link: '/folder/content/files' },
],
},
],
});
```
For best results, complete your entire doc article,static page then integrate this documentation sidebar menu with your documentation article,

This configuration output on sidebar left documentation page.

![astro docus](https://wsrv.nl/?url=https://public-files.gumroad.com/7wl3qx27efqty8q7w4px8c7dpd17&w=1000&output=webp)

----

#### Static Page

Static Page Astro Docus

In docus project, you can create a static page , for example about page or contact page. access on `src/content/docs/` and you can see example static article page in here.

![astro documentation themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/k2vmmf32ozlajw0ku0kwjd74gexu&w=1000&output=webp)

For add static page you can create new .mdx or .md files, or for simply step, copy and paste from example article .mdx or .md files, rename with your static page url , update title and description and write your content.

Frontformatter
```
---
title: Order Astro JS Blacks
description: Buy and Order Astro JS Blacks themes template complete project.
template: splash
tableOfContents: false
prev: false
next: false
---

import Nav from '../../widget/index_page/Nav.astro';
import Header from '../../widget/plan/Header.astro';
import Footer from '../../widget/index_page/Footer.astro';
import Help from '../../widget/Help.astro';
import '../../styles/doc.css';
import '../../styles/default.css';
<Nav/>



### This title about your static page article

You can write article on this area....



<Help/>
<Footer/>
```

Implementation
```
---
title: Order Astro JS Blacks
description: Buy and Order Astro JS Blacks themes template complete project.
template: splash
tableOfContents: false
prev: false
next: false
---
import Nav from '../../widget/index_page/Nav.astro';
import Header from '../../widget/plan/Header.astro';
import Footer from '../../widget/index_page/Footer.astro';
import Help from '../../widget/Help.astro';
import '../../styles/doc.css';
import '../../styles/default.css';

<Nav/>


### How to Use Blacks Astro JS Multipurpose Complete Themes Template

+ Click Buy This
+ Make Payment
+ Download Source Code Files 
+ Read Documentation


<Help/>
<Footer/>
```
Output Design UI

![astro starlight themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/vw2k30ve0a6zafbjvsnyfee3w772&w=1000&output=webp)


----

#### Pricing Page

For pricing page you just need to update on src/data/pricing/pricing.json

JSON code
```
{
"resources": [
  {
   "title": "Your pricing plan name ",
   "text": "Information about your pricing plan here...",
   "price": "insert price in here...",
   "link": "URL Link for this order.."
  },
  {
   "title": "Standard",
   "text": "Standard Package set - astro js blacks themes template source code + Tina headless CMS for local dev mode.",
   "price": "$105",
   "link": "https://www.fiverr.com/creativitas/design-presentation-website-for-marketing-product"
  },
  {
   "title": "Premium",
   "text": "PRO Package set - astro js blacks themes template source code + Cloud netlify decap cms + Setup Configuration hosting .",
   "price": "$155",
   "link": "https://www.fiverr.com/creativitas/design-your-modern-website-using-jekyll"
  },
  {
   "title": "Custom",
   "text": "Custom Package set - astro js blacks themes template source code + Cloud netlify decap cms + Setup Configuration hosting +.",
   "price": "$155",
   "link": "https://www.fiverr.com/creativitas/design-your-modern-website-using-jekyll"
  }
]
}
```

Output Design UI

![astro starlight themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/oc66xq8xrzevinyep3owf9jd6jk4&w=1000&output=webp)

----

#### Contact Page

Location src/content/docs/contact.mdx

In contact page is inlcude with contact form, for help you handle message from your customer , this concept is use airform server, so for first you can activation your email. Easy for use just sent message on your contact form, then click confirmation for activate this contact form.The contact page includes a contact form, to help you handle messages from your customers, this concept uses an airform server, so first you can activate your email. Easy to use, just send a message on your contact form, then click confirm from your email to activate this contact form.

frontmatter
```
---
title: "Contact Us"
description: "Need information ?? contact our team dev."
phone: "6285179858615"
email: "axcora@gmail.com"
address: "Bunerdo alegadro , 77 th  , Holywood - USA "
template: splash
tableOfContents: false
prev: false
next: false
---
```
output design UI

![astro starlight themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/eboz77si2r97l4idw7s0x487m253&w=1000&output=webp)

----

### Documentation Content Astro Docus

Now we can add documentation content, access on `src/content/docs` , create new folder for grouping your documentation, and name it with your doc categories .  
Or you can see grouping categories doc example such cms,  contact, folder, get start and others folder.

![astro starlight themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/48m6zsel1lqk1w2h6clj04npvlf7&w=1000&output=webp)

Create a new folder and name it with your documentation category group, for example getstart - this is for the first documentation schema. 
And later you will create content documentation with the following link `yourweb.com/getstart/`


![astro starlight themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/fsdhea90p783uh1u3k3a24607klb&w=1000&output=webp)

In the initial folder, we can now create new document content, to create a new article, you can simply copy and paste from the example article, 
and update according to your needs. Or create a new file, and name it with the title of your document, then write the markdown content.

Frontformatter
```
---
title: Gallery
description: Update gallery astro js themes template blacks project.
---
### Title in here...

Write your content about your documentation here...
```

Implementation
```
---
title: Gallery
description: Update gallery astro js themes template blacks project.
---

## Gallery Page

Gallery Page Astro JS Blacks Theme.

This area for displaying your image and video gallery.

You can update gallery index page , with access on `src/pages/gallery/index.md`

```

Output Design UI

![astro starlight themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/v8xjcpbqfb8po2qe7zi8qukwnsvh&w=1000&output=webp)

Once you have completed all your initial group document articles, we can now create an index page to make it easier for your users to access your document articles.

Create index.mdx files on your group doc articles. and add this frontformatter.
```
---
title: Get Start
description: Get Started with blacks astro js themes template
tableOfContents: false
next: false
---
import Data from '../../../data/index_page/hosting.json';
import { Card, CardGrid } from '@astrojs/starlight/components';


## {frontmatter.description}


<CardGrid>
{ Data.resources.map(({ title,text,link }) => ( 
  <Card title={title} icon="rocket">
    {text} <br/>
    <a href={link}>{title} info →</a>
  </Card>
  ))}
</CardGrid>
```

#### Group Categories Doc Index Page

Next we need to access on src/data/index_page/and create file for your index page getstart.json 

Next, you can customises the json files with your needs.

Json Code
```
{
    "resources": [
      {
       "title": "Vercel",
       "text": "Vercel Hosting",
       "link": "/hosting/vercel"
      },
      {
       "title": "Add your title article docs",
       "text": "Text information here...",
       "link": "URL for your articles..."
      },
      {
       "title": "Netlify",
       "text": "Netlify Hosting",
       "link": "/hosting/netlify"
      }
    ]
    }
```
And you can customises your get start index with your get start articles.

Implementation JSON code
```
{
    "resources": [
      {
       "title": "Vercel",
       "text": "Vercel Hosting",
       "link": "/hosting/vercel"
      },
      {
       "title": "Cloudflare",
       "text": "Cloudflare Hosting",
       "link": "/hosting/cloudflare"
      },
      {
       "title": "Netlify",
       "text": "Netlify Hosting",
       "link": "/hosting/netlify"
      },
      {
       "title": "Firebase",
       "text": "Google Firebase Host",
       "link": "/hosting/firebase"
      },
      {
       "title": "Surge",
       "text": "Surge Cloud Host",
       "link": "/hosting/surge"
      },
      {
       "title": "PHP",
       "text": "PHP Hosting",
       "link": "/hosting/php"
      }
    ]
    }
```

Output Design UI

![astro starlight themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/85m59kvsqwkt4qy6qvldfol8zcs0&w=1000&output=webp)

For add this display on your index files, you need to import your json. on your `index.mdx` files

`import Start from '../../../widget/index_page/getstart.astro';`

The complete JSON code look like this.
```
{
    "resources": [
      {
       "title": "Vercel",
       "text": "Vercel Hosting",
       "link": "/hosting/vercel"
      },
      {
       "title": "Cloudflare",
       "text": "Cloudflare Hosting",
       "link": "/hosting/cloudflare"
      },
      {
       "title": "Netlify",
       "text": "Netlify Hosting",
       "link": "/hosting/netlify"
      }
    ]
    }
```

#### Create New Group Doc Article

Create new grouping documentation is same like create this getstart Group doc .

For example you need to create a cms documentation group , you can create new group doc and name it with cms , on your `src/content/docs folder` 

complete source look like src/content/docs/cms

For create new article doc, you can create new files and name it with your article doc url, and insert the fontformatter format.

Example : `mycms.md`

Complete source : `src/content/docs/cms/mycms.md`
```
---
title: My CMS
description: My CMS new article
---
### Title in here...

Write your content about your documentation here...
```

You can add all articles to your documentation group.

Once you have completed all the articles, you can now create an index file to organize your group documents.

Before do that we need to create a Json Data, so you can access on `src/data/index_page/` and create your json data for your cms group , for example cms.json 
the complete source look like `src/data/index_page/cms.json`

Insert this JSON format code
```
{
    "resources": [
      {
       "title": "Your article cms title doc 1",
       "text": "Text information for cms article doc 1",
       "link": "URL Link for your artilce doc 1"
      },
      {
       "title": "Your article cms title doc 2",
       "text": "Text information for cms article doc 2",
       "link": "URL Link for your artilce doc 2"
      },
      {
       "title": "New add cms title doc",
       "text": "New Text information for cms article doc",
       "link": "URL Link for your new artilce doc "
      }
    ]
    }
```
Implementation
```
{
    "resources": [
      {
       "title": "Decap CMS",
       "text": "Headless Git Hybrid Tech",
       "link": "/cms/decap"
      },
      {
       "title": "Tina CMS",
       "text": "Dev Mode Headless CMS",
       "link": "/cms/tina"
      },
      {
       "title": "Cloudcannon",
       "text": "Headless Git Cloud System",
       "link": "/cms/cloudcannon"
      },
      {
       "title": "Other CMS",
       "text": "Other Headless CMS",
       "link": "/cms/others"
      }
    ]
    }
```
And we need to import this json data files in to your `index.mdx` files. 

`import Data from '../../../data/index_page/cms.json';`

so access on src/content/docs/cms/index.mdx or you can paste this code in to your index.mdx files.
```
---
title: CMS Group article
description: This is cms group article description index page
tableOfContents: false
next: false
---
import Data from '../../../data/index_page/cms.json';
import { Card, CardGrid } from '@astrojs/starlight/components';


## {frontmatter.description}


<CardGrid>
{ Data.resources.map(({ title,text,link }) => ( 
  <Card title={title} icon="rocket">
    {text} <br/>
    <a href={link}>{title} info →</a>
  </Card>
  ))}
</CardGrid>
```

Output Design UI

![astro starlight themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/1tz4iuy7m51hk6y5ka21drwqinuw&w=1000&output=webp)

Note: If you want to create index page for your group documentation content, for first you need to create 
a json data for your group article, next you can import the JSON data into your index.mdx files on your group article.



---


### Blog Articles Astro Docus

Astro docus project is inlcude with blog content, access on `src/content/pages/blog` .

![astro js starlight blog](https://wsrv.nl/?url=https://public-files.gumroad.com/wtn51dg2g6q3a8l35p66czcqdh3t&w=1000&output=webp)

You can see example article for blog page in here. Next you can add new content article , with create new files , and name it file with your article, and write your content. Or for simple step , you can copy and paste from example article, rename files with your article blog url and update title, description and others with your needed.You can see an example of an article for a blog page here. Next you can add new article content, by creating a new file, and naming the file with your article, and writing your content. Or for a simple step, you can copy and paste from the example article, rename the file with your article's blog url and update the title, description, etc. according to your needs.

Frontformatter
```
---
layout: ../../design/blog/blogpost.astro
title: "Your blog article title here..."
description: "Your blog description title here..."
image: URL Image or CDN image here...
pubDate: 2023-12-12
tags: ["astro", "tags in here", " astro template", "astro themes"]
categories: ["categories in here"]
---

### Hello World

Write your content article here...
```
Implementation
```
---
layout: ../../design/blog/blogpost.astro
title: "Image Detail Astro JS Template"
description: "Detail image gallery content article - astro js themes"
image: /src/assets/image.png
pubDate: 2023-12-12
tags: ["astro", "image gallery", " astro template", "astro themes"]
categories: ["image"]
---
When your site visitors or customers click on one of the image galleries, they will be directed to the image detail page,visitors and customers can see detailed information from your image gallery.

[Read how to change image gallery page here →](/getstart/gallery/#image-gallery)


[Run project demo →](https://conceptualart.pages.dev/)

or

[Order this themes →](https://www.hockeycomputindo.com/themes/astro/blacks-complete-astro-themes/)
```

Output Design UI

![astro js starlight blog](https://wsrv.nl/?url=https://public-files.gumroad.com/n100isgpqxrvbubb9hnfpvh0g238&w=1000&output=webp)


After you have finished creating all the articles, your blog articles will be listed in the blog index page area.

![astro js starlight blog](https://wsrv.nl/?url=https://public-files.gumroad.com/ct1jo0xine4p8jmua4gw1gaxg2ga&w=1000&output=webp)

You can set pagination and post display number, just open and update in `[..page].astro` file.

Change this code
```
  return paginate(formattedPosts, {
    pageSize: input post number here,
  })
}
```
The implementation if we want to display 12 posts in pagination.
```
  return paginate(formattedPosts, {
    pageSize: 12,
  })
}
```

---

### Update Design UI

After you have configuration , create documentation content, blog article, and others. Now you can update your design UI, like setup your navigation , 
sidebar doc , and footer menu for static page, home page,doc page or blog page.After you have configured, create documentation content, blog articles, etc. 
Now you can update your design UI, such as setting navigation menus and footers for static pages, home pages, or blog pages.

Access on `data/configuration`

Navigation Home Page + Static Page

Update static and home page nav - open on `data/configuration/home/homepage.json`

Complete JSON Code
```
{
    "title": "Blacks Astro Themes",
    "description": "Multipurpose Premium Astro JS Elegant Themes template with complete features",
    "icon": "/src/assets/astrojs.svg",
    "image": "/src/assets/newastro.png",
    "navbar": [
        {
         "nav": "Home",
         "link": "/"
        },
        {
         "nav": "Doc",
         "link": "/getstart/"
        },
        {
         "nav": "Blog",
         "link": "/blog/"
        },
        {
         "nav": "Plan",
         "link": "/plan/"
        }
    ],
    "footer1": "Menu",
    "footer1_nav": [
        {
         "nav": "Home Page",
         "link": "/"
        },
        {
         "nav": "Documentation",
         "link": "/getstart/"
        },
        {
         "nav": "Blog Page",
         "link": "/blog/"
        },
        {
         "nav": "Pricing Plan",
         "link": "/plan/"
        }
    ],
    "footer2": "Start",
    "footer2_nav": [
        {
         "nav": "Get Start",
         "link": "/getstart/"
        },
        {
         "nav": "Folder Structure",
         "link": "/folder/"
        },
        {
         "nav": "Headless CMS",
         "link": "/cms/"
        },
        {
         "nav": "Cloud Hosting",
         "link": "/hosting/"
        }
    ],
    "footer3": "Project",
    "footer3_nav": [
        {
         "nav": "Astro Blacks",
         "link": "/project/astroblacks/"
        },
        {
         "nav": "Astro Rent Car",
         "link": "/project/astrocar/"
        },
        {
         "nav": "Astro Docus",
         "link": "/project/astrodoc/"
        },
        {
         "nav": "Source Code",
         "link": "/project/astrothemes/"
        }
    ],
    "footer4": "Contact",
    "footer4_nav": [
        {
         "nav": "Sent Message",
         "link": "/message/"
        },
        {
         "nav": "WhatsApp Chat",
         "link": "https://wa.me/6285179858615"
        },
        {
         "nav": "Sent Email",
         "link": "mailto:axcora@gmail.com"
        },
        {
         "nav": "Hire Developer",
         "link": "https://www.fiverr.com/creativitas/"
        }
    ]
}
```
Navbar area
```
"title": "Blacks Astro Themes",
    "description": "Multipurpose Premium Astro JS Elegant Themes template with complete features",
    "icon": "/src/assets/astrojs.svg",
    "image": "/src/assets/newastro.png",
    "navbar": [
        {
         "nav": "Home",
         "link": "/"
        },
        {
         "nav": "Add new nav here...",
         "link": "Link URL for your new nav..."
        },
        {
         "nav": "Doc",
         "link": "/getstart/"
        }
    ],
```
For add new you can copy and paste from example code, then edit with you needed. see the example code.

Output Design UI

![starlight astro js themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/yyb7ywavgiiqisfxsry13m5u9euy&w=1000&output=webp)


Footer area 
```

    "footer1": "Menu",
    "footer1_nav": [
        {
         "nav": "Home Page",
         "link": "/"
        },
        {
         "nav": "New Nav here..",
         "link": "URL for new nav.."
        },
        {
         "nav": "Blog Page",
         "link": "/blog/"
        }
    ],
    "footer2": "Start",
    "footer2_nav": [
        {
         "nav": "Get Start",
         "link": "/getstart/"
        },
        {
         "nav": "New Nav here..",
         "link": "URL for new nav.."
        },
        {
         "nav": "Headless CMS",
         "link": "/cms/"
        }
    ],
    "footer3": "Project",
    "footer3_nav": [
        {
         "nav": "Astro Blacks",
         "link": "/project/astroblacks/"
        },
        {
         "nav": "Source Code",
         "link": "/project/astrothemes/"
        }
    ],
    "footer4": "Contact",
    "footer4_nav": [
        {
         "nav": "Sent Message",
         "link": "/message/"
        },
        {
         "nav": "Add your new nav here...",
         "link": "Link for your footer nav.."
        },
        {
         "nav": "Sent Email",
         "link": "mailto:axcora@gmail.com"
        }
    ]
```
For add new you can copy and paste from example code, then edit with you needed. see the example code.

Output Design UI

![starlight astro js themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/klzt960lto147sf42wv1senz6al2&w=1000&output=webp)

Update Blog Page Nav

Next , you can update blog page nav - open on `data/configuration/blog/blogpage.json`

Complete JSON Code
```
{
    "url": "https://astrodoc.pages.dev/blog",
    "title": "Blog Astro Themes",
    "description": "Update blog Docus Astro JS Starlight Themes template with complete features",
    "categories_page_title": "Categories Astro Themes",
    "categories_page_description": "Update blog Docus Astro JS Starlight Themes template with complete - categories",
    "tags_page_title": "Tags Astro Themes",
    "tags_page_description": "Update blog Docus Astro JS Starlight Themes template with complete features - tagging",
    "icon": "/src/assets/astrojs.svg",
    "image": "/src/assets/newastro.png",
    "navbar": [
        {
         "nav": "Home",
         "icon": "/src/assets/homeblog.svg",
         "link": "/"
        },
        {
         "nav": "Doc",
         "icon": "/src/assets/homedoc.svg",
         "link": "/getstart/"
        },
        {
         "nav": "Blog",
         "icon": "/src/assets/bloggers.svg",
         "link": "/blog/"
        },
        {
         "nav": "Plan",
         "icon": "/src/assets/blogcontact.svg",
         "link": "/plan/"
        }
    ]
}
```
Categories title and description is for your categories title and description page , Tags title and categories for your blog tag page.

Implementation Blog List Page
```
"title": "Blog Astro Themes",
"description": "Update blog Docus Astro JS Starlight Themes template with complete features",
```
Output Design UI


![starlight astro js themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/5x29cn5m4jqmzjgs2mb0ozmwgutx&w=1000&output=webp)

Implementation Categories Page
```
"categories_page_title": "Categories Astro Themes",
"categories_page_description": "Update blog Docus Astro JS Starlight Themes 
```
Output Design UI


![starlight astro js themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/0i0en7w3fk5x2yhhci5thfi519od&w=1000&output=webp)

Implementation Tag page
```
"tags_page_title": "Tags Astro Themes",
"tags_page_description": "Update blog Docus Astro JS Starlight Themes template with complete features - tagging",
```
Output Design UI

![starlight astro js themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/2907bxv5kohv0xa36xb3ovynd2rr&w=1000&output=webp)

Implementation navbar blog
```
"icon": "/src/assets/astrojs.svg",
    "image": "/src/assets/newastro.png",
    "navbar": [
        {
         "nav": "Home",
         "icon": "/src/assets/homeblog.svg",
         "link": "/"
        },
        {
         "nav": "Doc",
         "icon": "/src/assets/homedoc.svg",
         "link": "/getstart/"
        },
        {
         "nav": "Blog",
         "icon": "/src/assets/bloggers.svg",
         "link": "/blog/"
        },
        {
         "nav": "Plan",
         "icon": "/src/assets/blogcontact.svg",
         "link": "/plan/"
        }
    ]
```
Output Design UI on Blog page list

![starlight astro js themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/yjji0zmivodu4a0tos03rvbudm9i&w=1000&output=webp)

Output Design UI on Blog article page

![starlight astro js themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/7ziegl2aibs27i21xn937lw8lw9j&w=1000&output=webp)


Sidebar Doc

Next you need to config your sidebar documentation , so you can access on `astro.config.mjs`
```
export default defineConfig({
site: 'your website url in here',
integrations: [
starlight({
title: 'Your website title',
logo: {src: 'Image logo URL in here..',},
customCss: ['Your custom css in here..',],
social: { github: 'Your github repo here..', },
sidebar: [
{label: 'Title for your categories documentation article..',
items: [
{ label: 'Your doc article 1', link: 'Link url article 1 in here..' },
{ label: 'Your doc article 2 ', link: 'Link url article 2 in here..' },
],
},

{label: 'New categories title for documentation article..',
items: [
{ label: 'Your new doc here..', link: 'Link url in here...' },
{ label: 'New doc 2 grouping in here...',
items: [
{ label: 'New doc 2 title article 1', link: 'Link URL for new doc 1 ' },
{ label: 'New doc 2 title article 1', link: 'Link URL for new doc 2 ' },
],
},
],
});
```
Customise the sidebar doc with your needs, integration label with your doc url link, and save it.

Output Design UI

![starlight astro js themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/7wl3qx27efqty8q7w4px8c7dpd17&w=1000&output=webp)

---

### Push Docus Project on Github.

Before push your project, you need to add your domain.

For first you can open `astro.config`

and change site url with your domain name .

Json Code
```
export default defineConfig({
	site: 'https://astrodoc.pages.dev',
	integrations: [
});
```
And open `src/data/config.json` change url with your domain name.

#### Github

Register and create an account on github

Next you can create new repo , check image

![astro js documentation themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/ex6o4c1tuv7sjj46sdkrdhd0skzh&w=1000&output=webp)

Name it your repo , then select your project for public or private, Then you can click create repo button.

Next, You need to following github command.

For first access your project using terminal , then copy and paste command script from github.

Example 
```
git init
git add .
git commit -m "first commit for my astro website"
git remote add origin https://github.com/username/your-repo-name
git push -u origin master
```
Change username with your github username ,and change your-repo-name with your github repo

And you have successfully push your project on github repo.

Output

![astro js documentation themes template](https://wsrv.nl/?url=https://public-files.gumroad.com/3m9exvmjt42dc7gd6kh81o8cupqp&w=1000&output=webp)

Next step, you need to register on modern static host provider for deploy your project and make your website live.

---

### Publish Astro Docus Project Theme.

For deploy and make your website live, so you need to register on modern static host provider, for example, cloudflare , netlify or vercel.

+ Register with your github account
+ Next you can click create new project app for netlify and vercel or pages for cloudflare
+ And you can click select and integration with your github repo project.
+ After you have integration with your github account, now you can select your github repo
+ Next you can click deploy, and select astro as framework.
+ Click Deploy
+ Congratulations your website is live now !!

---

### Headless CMS for Astro JS Blacks Theme.

If you want to work with CMS , so you can use headless git cms for best solutions.

Same like other cms, with headless cms we can update website and blog quickly.

Include with credential security for login on backend admin, make your website secure.

We can use netlify decap cms.

![Astro cms](https://wsrv.nl/?url=https://public-files.gumroad.com/59yp0bq9l6swfgocjyp2g87bmpts&w=1000&output=webp)

Credential login with google or github account

![Astro cms](https://wsrv.nl/?url=https://public-files.gumroad.com/74mbmz1ymcyboz44mekpxqfslipb&w=1000&output=webp)

Dashboard area

![Astro cms](https://wsrv.nl/?url=https://public-files.gumroad.com/560kbpjzxrvfinjgpefpqaphuxm9&w=1000&output=webp)

Blog article post

![Astro cms](https://wsrv.nl/?url=https://public-files.gumroad.com/7mvvw3o9r9pkxt496rzbmxzc75zy&w=1000&output=webp)

Write your article or update page


You can build your backend headless cms with decap cms.

![Astro cms](https://wsrv.nl/?url=https://public-files.gumroad.com/qx0k8y52e8rwznep9fqcecu8raws&w=1000&output=webp)

Or you can use headless cms for your dev local mode with Tina CMS

If you interest work with headless cms, so you can use our services for develope your backend headless cms admin for your project.
